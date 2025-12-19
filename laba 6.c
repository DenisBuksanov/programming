#include <stdio.h>
int main() {
    int N;
    printf("Введите N (1 <= N <= 3): ");
    scanf("%d", &N);

    int matrix[3][3];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = i + j + 1;
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }
    int det = 0;
    if (N==1) {
        det = matrix[0][0];
    }
    else if (N==2) {
        det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    else if (N==3) {
        det = matrix[0][0] * matrix[1][1] * matrix[2][2] + matrix [0][1] * matrix[1][2] * matrix[2][0] + matrix[1][0] * matrix[2][1] * matrix[0][2] - matrix[0][2] * matrix[1][1] * matrix[2][0] - matrix[0][1] * matrix[1][0] * matrix[2][2] - matrix[0][0] * matrix[1][2] * matrix[2][1];
    
    }
    printf("Определитель матрицы: %d\n", det);
    return 0;
}
