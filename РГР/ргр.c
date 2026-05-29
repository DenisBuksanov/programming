#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char og[256];
    char transl[5][256];
    int t_count;
} DictRec;

int make_low(const char* src, char* dst) { 
    strcpy(dst, src);
    unsigned char b1 = dst[0], b2 = dst[1];
    if (b1 >= 'A' && b1 <= 'Z') { dst[0] += 32; return 1; }
    if (b1 == 0xD0 && b2 >= 0x90 && b2 <= 0xAF) {
        if (b2 <= 0x9F) dst[1] = b2 + 0x20;
        else { dst[0] = 0xD1; dst[1] = b2 - 0x20; }
        return 1;
    }
    return 0;
}

void fprint_upper(FILE *out, const char *str) {
    unsigned char b1 = str[0], b2 = str[1];
    if (b1 >= 'a' && b1 <= 'z') {
        fprintf(out, "%c%s", b1 - 32, str + 1);
    }
    else if (b1 == 0xD0 && b2 >= 0xB0 && b2 <= 0xBF) {
        fprintf(out, "%c%c%s", 0xD0, b2 - 0x20, str + 2);
    } 
    else if (b1 == 0xD1 && b2 >= 0x80 && b2 <= 0x8F) {
        fprintf(out, "%c%c%s", 0xD0, b2 + 0x20, str + 2);
    } 
    else {
        fprintf(out, "%s", str);
    }
}

DictRec* load_dict(const char *filename, int *dict_size) {
    FILE *f = fopen(filename, "r");
    if (!f) {
        printf("Ошибка: файл словаря не найден\n");
        return NULL;
    }

int capacity = 10, count = 0;
    DictRec *dict = malloc(capacity * sizeof(DictRec));

    if (!dict) {
        printf("Ошибка: Не удалось выделить память под словарь.\n");
        fclose(f);
        return NULL;
    }

    char line[1024];
    while (fgets(line, sizeof(line), f)) {
        char *word = strtok(line, " \n\r\t");
        if (!word) continue;

        int idx = -1;
        for (int i = 0; i < count; i++) 
            if (strcmp(dict[i].og, word) == 0) { idx = i; break; }

        if (idx == -1) {
            if (count >= capacity) {
                capacity *= 2;
                DictRec *temp = realloc(dict, capacity * sizeof(DictRec));
                

                if (!temp) {
                    printf("Ошибка: Нехватка памяти при расширении словаря.\n");
                    free(dict);
                    fclose(f);
                    return NULL;
                }
                dict = temp;
            }
            idx = count++;
            strcpy(dict[idx].og, word);
            dict[idx].t_count = 0;
        }

        char *trans;
        while ((trans = strtok(NULL, " \n\r\t")) && dict[idx].t_count < 5) 
            strcpy(dict[idx].transl[dict[idx].t_count++], trans);
    }
    fclose(f);

    if (count == 0) {
    printf("Предупреждение: Файл словаря '%s' пуст или не содержит корректных записей.\n", filename);
        free(dict);
        return NULL;
    }
    *dict_size = count;
    return dict;
}

void transl_word(const char *word, DictRec *dict, int dict_size, FILE *out) {
    char search[256];
    int is_upper = make_low(word, search);

for (int i = 0; i < dict_size; i++) {
        if (strcmp(search, dict[i].og) == 0) {
            for (int j = 0; j < dict[i].t_count; j++) {
                if (is_upper) {
                    fprint_upper(out, dict[i].transl[j]);
                } else {
                    fprintf(out, "%s", dict[i].transl[j]);
                }
                
                if (j < dict[i].t_count - 1) {
                    fprintf(out, "/");
                }
            }
            return;
        }
    }
    fprintf(out, "%s", word);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
    printf("Используйте: %s <текст.txt> <словарь.txt> <результат.txt>\n", argv[0]);
        return 1;
    }

    int dict_size = 0;
    DictRec *dict = load_dict(argv[2], &dict_size);
    if (!dict) {
        return 1;
    }

    FILE *in = fopen(argv[1], "r");
    if (!in) {
        printf("Ошибка: Не удалось открыть файл с исходным текстом '%s'.\n", argv[1]);
        free(dict);
        return 1;
    }
    FILE *out = fopen(argv[3], "w");
    if (!out) {
        printf("Ошибка: Не удалось создать или открыть на запись файл результата '%s'.\n", argv[3]);
        fclose(in);
        free(dict);
        return 1;
    }

char token[256];
    int pos = 0;
    int ch;

    while ((ch = fgetc(in)) != EOF) {
        if (isalpha((unsigned char)ch) || (unsigned char)ch >= 128) {
            if (pos < 255) token[pos++] = ch;
        } else {
            if (pos > 0) {
                token[pos] = '\0';
                transl_word(token, dict, dict_size, out);
                pos = 0;
            }
            fputc(ch, out);
        }
    }
    if (pos > 0) {
        token[pos] = '\0';
        transl_word(token, dict, dict_size, out);
    }

    free(dict);
    fclose(in); fclose(out);
    printf("Успех: Перевод успешно выполнен. Результат сохранен в '%s'.\n", argv[3]);
    return 0;
}
