#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10 

struct employee {
    char name[50];
    int id;
    char level[20];
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Инструкция: %s staff.csv\n", argv[0]);
        exit(1);
    }

    // чтение из csv

    FILE *csv_file = fopen(argv[1], "r");
    if (csv_file == NULL) {
        printf("В файле %s на строке %d: Ошибка открытия CSV\n", __FILE__, __LINE__);
        exit(1);
    }

    struct employee staff[N];
    char line[100];
    int count = 0;

    printf("%-31s | %-10s | %-20s\n", "Имя Фамилия", "ID", "Уровень");
    printf("--------------------------------------------\n");

    while (fgets(line, sizeof(line), csv_file) && count < N) {
        line[strcspn(line, "\r\n")] = 0; 

        char *name_part = strtok(line, ";");
        char *id_part = strtok(NULL, ";");
        char *level_part = strtok(NULL, ";");

        if (name_part && id_part && level_part) {
            strcpy(staff[count].name, name_part);
            staff[count].id = atoi(id_part);
            strcpy(staff[count].level, level_part);

            printf("%-21s | %-10d | %-10s\n", staff[count].name, staff[count].id, staff[count].level);
            count++;
        }
    }
    fclose(csv_file);

    // запись в бинарный файл

    FILE *bin_write = fopen("database.dat", "wb");
    if (bin_write == NULL) {
        printf("В файле %s на строке %d: Ошибка создания базы данных\n", __FILE__, __LINE__);
        exit(1);
    }

    printf("\nСохранение данных в database.dat...\n");
    size_t written = fwrite(staff, sizeof(struct employee), count, bin_write);
    if (written != count) {
        printf("Ошибка при записи в файл database.dat\n");
        fclose(bin_write);
        exit(1);
    }
    fclose(bin_write);

    // поиск в бинарном

    FILE *bin_read = fopen("database.dat", "rb");
    if (bin_read == NULL) {
        printf("В файле %s на строке %d: Ошибка открытия базы для поиска\n", __FILE__, __LINE__);
        exit(1);
    }

    int search_id;
    printf("\nВведите ID сотрудника для поиска: ");
    if (scanf("%d", &search_id) != 1) {
        printf("Ошибка: Введите числовой ID.\n");
        exit(1);
    }

    struct employee temp;
    int found = 0;

    while (fread(&temp, sizeof(struct employee), 1, bin_read) == 1) {
        if (temp.id == search_id) {
            printf("\n--- Сотрудник найден ---\n");
            printf("Имя:     %s\nID:      %d\nУровень: %s\n", temp.name, temp.id, temp.level);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nОшибка: Сотрудник с ID %d не найден в базе.\n", search_id);
    }

    fclose(bin_read);
    return 0;
}
