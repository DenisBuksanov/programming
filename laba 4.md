#include <stdio.h>
int main() {
    int a;
    printf("Введите число: ");
    scanf("%d", &a);

    int shift;
    printf("Сдвиг: ");
    scanf("%d", &shift);
    unsigned int result = (a << shift) | ((1 << shift) - 1);
    printf("Результат сдвига: %u\n", result);
    return 0;
}
