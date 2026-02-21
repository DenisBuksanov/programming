#ifndef CRIPTO_H
#define CRIPTO_H

#define N 6

struct Cripto {
    char t[5];  // тикер
    int q;      // количество
    int p;      // цена
    int z;      // изменение 24ч
};

void C(struct Cripto cryptos[]);
void generate(struct Cripto cryptos[]);
void sort(struct Cripto cryptos[]);

#endif
