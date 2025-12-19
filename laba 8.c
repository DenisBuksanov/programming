#include <stdio.h>
void input_matrix(int a[50][50], int n, int *mini, int *minj) {
    printf("Введите элементы матрицы %dx%d:\n", n, n);
    *mini = *minj = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            if ((i == 0 && j == 0) || a[i][j] < a[*mini][*minj]) {
                *mini = i;
                *minj = j;
            }
        }
    printf("\n");
}
void print_matrix(int a[50][50], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf(" %3d  ", a[i][j]);
        }
        printf("\n");
    }
}

int squareum(int a[50][50], int row0, int col0, int size, int k, int square[2500]) {
    int sum = 0, idx = 0;
    for (int i = row0; i < row0 + size; i++) {
        for (int j = col0; j < col0 + size; j++) {
            a[i][j] *= k;
            square[idx++] = a[i][j];
            sum += a[i][j];
        }
    }
    printf("Итоговая сумма: %d\n", sum);
    return sum;
}
int main() {
    int n;
    printf("Введите размер матрицы: ");
    scanf("%d", &n);

    int a[50][50], square[2500];
    int mini, minj;

    input_matrix(a, n, &mini, &minj);

    int sizeH = n - mini;
    int sizeW = minj + 1;
    int size;
    if (sizeH < sizeW) {
        size = sizeH;
    } else {
        size = sizeW; 
    }

    int row0 = mini;
    int col0 = minj - size + 1;

    int k;
    printf("Введите число для умножения элементов квадрата: ");
    scanf("%d", &k);
    printf("\n");

    squareum(a, row0, col0, size, k, square);
    print_matrix(a, n);
    printf("\n");
    printf("Массив элементов квадрата: ");
    for (int i = 0; i < size * size; i++)
        printf("%d ", square[i]);
    printf("\n");
    return 0;
}
