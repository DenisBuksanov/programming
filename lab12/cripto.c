#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "cripto.h"

void C(struct Cripto cryptos[]) {
    printf("%-10s %-21s %-10s %-15s\n", "Тикер", "Количество", "Цена", "Изменение 24ч");
    for (int i = 0; i < N; i++) {
        printf("%-6s %-10d %-10d %+d\n", cryptos[i].t, cryptos[i].q, cryptos[i].p, cryptos[i].z);
    }
}

void generate(struct Cripto cryptos[]) {
    srand(time(NULL));
    const char* tickers[] = {"BTC", "ETH", "ADA", "DOGE", "SOL", "LTC"};
    for (int i = 0; i < N; i++) {
        strcpy(cryptos[i].t, tickers[i]);
        cryptos[i].q = 1 + rand() % 100;
        cryptos[i].p = 1000 + rand() % 90000;
        cryptos[i].z = -500 + rand() % 1001;
    }
}

void sort(struct Cripto cryptos[]) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - 1 - i; j++) {
            if (cryptos[j].p > cryptos[j + 1].p) {
                struct Cripto temp = cryptos[j];
                cryptos[j] = cryptos[j + 1];
                cryptos[j + 1] = temp;
            }
        }
    }
}
