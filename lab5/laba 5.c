#include <stdio.h>

void average(int sum, int count) {
    double a = (double)sum / count;
    printf("Среднее арифметическое между ними: %.2f\n", a);
}

int maxIndex(int x[], int n) {
    int max_index = 0;
    for(int i = 1; i < n; i++) {
        if(x[i] > x[max_index]) {
            max_index = i;
        }
    }
    return max_index;
}

int minIndex(int x[], int n) {
    int min_index = 0;
    for(int i = 1; i < n; i++) {
        if(x[i] < x[min_index] && x[i] % 2 == 0) {
            min_index = i;
        }
    }
    return min_index;
}

int main() {
    int n;
    printf("Введите размер массива: ");
    scanf("%d", &n);
    
    int x[n];
    printf("Введите элементы массива:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%d", &x[i]);
    }
    
    int min_index = minIndex(x, n);
    int max_index = maxIndex(x, n);
    
    int start, end;
    if (min_index < max_index) {
        start = min_index;
        end = max_index;
    } else {
        start = max_index;
        end = min_index;
    }
    
    int sum = 0;
    int count = 0;
    for (int i = start + 1; i < end; i++) {
        sum += x[i];
        count++;
    }
    
    printf("\nМинимальный элемент: X[%d] = %d\n", min_index, x[min_index]);
    printf("Максимальный элемент: X[%d] = %d\n", max_index, x[max_index]);
    
    average(sum, count);
    return 0;
}
