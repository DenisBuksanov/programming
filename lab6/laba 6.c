 #include <stdio.h>
#define N 3
int main() {
    double matrix[N][N] = {
        {3, 2, 1},
        {6, 5, 4},
        {9, 8, 7}};
    double b[N] = {1, -2, 3};
    printf("Система:\n");
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%.0fx%d", matrix[i][j], j+1);
            if(j < N - 1)
                printf(" + ");
        }
        printf(" = %.f\n", b[i]);
    }
    double det;
    double det1;
    double det2;
    double det3;
    double x;
    double y;
    double z;
    det = matrix[0][0]*matrix[1][1]*matrix[2][2] + matrix[0][1]*matrix[1][2]*matrix[2][0] + matrix[0][2]*matrix[1][0]*matrix[2][1] - matrix[0][2]*matrix[1][1]*matrix[2][0] - matrix[0][1]*matrix[1][0]*matrix[2][2] - matrix[0][0]*matrix[1][2]*matrix[2][1];
        if(det == 0) {
        printf("Определитель равен 0! Система не имеет единственного решения.\n");
        return 1;
    }
    det1 = b[0]*matrix[1][1]*matrix[2][2] + matrix[0][1]*matrix[1][2]*b[2] + matrix[0][2]*b[1]*matrix[2][1] - matrix[0][2]*matrix[1][1]*b[2] - matrix[0][1]*b[1]*matrix[2][2] - b[0]*matrix[1][2]*matrix[2][1];
    det2 = matrix[0][0]*b[1]*matrix[2][2] + b[0]*matrix[1][2]*matrix[2][0] + matrix[0][2]*matrix[1][0]*b[2] - matrix[0][2]*b[1]*matrix[2][0] - b[0]*matrix[1][0]*matrix[2][2] - matrix[0][0]*matrix[1][2]*b[2];
    det3 = matrix[0][0]*matrix[1][1]*b[2] + matrix[0][1]*b[1]*matrix[2][0] + b[0]*matrix[1][0]*matrix[2][1] - b[0]*matrix[1][1]*matrix[2][0] - matrix[0][1]*matrix[1][0]*b[2] - matrix[0][0]*b[1]*matrix[2][1];
    x = det1/det;
    y = det2/det;
    z = det3/det;
    printf("\n");
    printf("det: %.2f\n", det);
    printf("det1: %.2f\n", det1);
    printf("det2: %.2f\n", det2);
    printf("det3: %.2f\n", det3);
    printf("x = %.2f\n", x);
    printf("y = %.2f\n", y);
    printf("z = %.2f\n", z);
    return 0;
}

