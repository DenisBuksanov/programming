#include <stdio.h>
#include <stdlib.h>

// Скомпилируй и запусти меня
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
    
}
void init(int **arr, int *a) { 
    *arr = malloc(*a * sizeof(int));
    for (int i = 0; i < *a; ++i) { 
        (*arr)[i] = i;    
    }
    *a = 5;   
}

int main() {
    int *arr = NULL;
    int n = 10;

    init(&arr, &n);

    // n = ?
    printf("%d\n", n);
    for (int i = 0; i < n; ++i) {
        printf("%d\n", arr[i]);
    }

    free(arr);
    return 0;
}
