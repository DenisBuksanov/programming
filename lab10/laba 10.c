#include <stdio.h>
struct Data {
    int den;
    int mesyac;
    int god;
};
    struct Data d;
    
struct Data vvod_daty() {
    printf("Введите день: ");
    scanf("%d", &d.den);
    printf("Введите месяц: ");
    scanf("%d", &d.mesyac);
    printf("Введите год: ");
    scanf("%d", &d.god);
    return d;
}

int opredelit_dekadu(struct Data d) {
    if (d.den >= 1 && d.den <= 10) {
        return 1;
    } else if (d.den >= 11 && d.den <= 20) {
        return 2;
    } else {
        return 3;
    }
}

char* opredelit_sezon(struct Data d) {
    if (d.mesyac == 12 || d.mesyac == 1 || d.mesyac == 2) {
        return "Зима";
    } else if (d.mesyac >= 3 && d.mesyac <= 5) {
        return "Весна";
    } else if (d.mesyac >= 6 && d.mesyac <= 8) {
        return "Лето";
    } else if (d.mesyac >= 9 && d.mesyac <= 11) {
        return "Осень";
    }
    return "";
}

int opredelit_vek(struct Data d) {
    if (d.god == 2000) {
        return 20;
    } else {
        return (d.god - 1) / 100 + 1;
    }
}

int main() {
    int n;
    char s[50];
    printf("Введите количество человек: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("\n--- Человек %d ---\n", i + 1);
        printf("Введите имя: ");
        scanf("%s", s);

        struct Data rozhdeniya = vvod_daty();
        int dekada = opredelit_dekadu(rozhdeniya);
        int vek = opredelit_vek(rozhdeniya);

        printf("\nИнформация о %s:\n", s);
        printf("Дата рождения: %02d.%02d.%d\n", rozhdeniya.den, rozhdeniya.mesyac, rozhdeniya.god);
        printf("Декада: %d-я декада месяца\n", dekada);
        printf("Сезон: %s\n", opredelit_sezon(rozhdeniya));
        printf("Век: %d-й век\n", vek);
    }
    return 0;
}

