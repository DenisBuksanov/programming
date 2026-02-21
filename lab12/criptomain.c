#include <stdio.h>
#include "cripto.h"

int main() {
    struct Cripto cryptos[N];
    generate(cryptos);

    printf("\n==== Криптовалюты до сортировки ====\n");
    C(cryptos);

    sort(cryptos);
    printf("\n==== Криптовалюты после сортировки ====\n");
    C(cryptos);

    return 0;
}
