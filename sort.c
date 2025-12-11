#include <stdio.h>
void bubble_sort(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}
int main() {
    int a[] = {4, 2, 0, 8, 1};
    int n = sizeof(a) / sizeof(a[0]);
    printf("Исходный массив: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    bubble_sort(a, n);
    printf("Отсортированный массив: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
// Комментарий к функции
// Еще один комментарий