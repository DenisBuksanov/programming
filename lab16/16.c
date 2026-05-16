#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* potok(void* arg) {
    for (int i = 1; i <= 5; i++) {
        printf("Дочерний поток: слово %d\n", i);
        usleep(80000);
    }
    return NULL;
}
void zapusk_12() {
    printf("\nзадание 1,2: Создать поток Ожидание потока\n");
    pthread_t tid;
    pthread_create(&tid, NULL, potok, NULL);
    pthread_join(tid, NULL);
    for (int i = 1; i <= 5; i++) {
        printf("Родительский поток: слово %d\n", i);
    }
}

void* potok_prmtr(void* arg) {
    char* text = (char*)arg;
    printf("Поток [%p] выводит: %s\n", (void*)pthread_self(), text);
    return NULL;
}
void zapusk_3() {
    printf("\nзадание 3: Передача параметров\n");
    pthread_t threads[4];
    char* m[] = {"Первый", "Второй", "Третий", "Четвертый"};
    for (int i = 0; i < 4; i++) {
        pthread_create(&threads[i], NULL, potok_prmtr, (void*)m[i]);
    }
    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }
}

void och_otm(void* arg) {
    printf("[Очистка] Поток отменен. Ресурсы очищены.\n");
}
void* otmena(void* arg) {
    pthread_cleanup_push(och_otm, NULL);
    while(1) {
        printf("[Дочерний] Работаю...\n");
        sleep(1);
    }
    pthread_cleanup_pop(0);
    return NULL;
}
void zapusk_45() {
    printf("\nзадание 4,5: Отмена и очистка\n");
    pthread_t tid;
    pthread_create(&tid, NULL, otmena, NULL);
    printf("Ждём 2 секунды...\n");
    sleep(2);
    printf("Отменяем поток...\n");
    pthread_cancel(tid);
    pthread_join(tid, NULL);
}

void* sleepsort(void* arg) {
    int val = *(int*)arg;
    free(arg);
    sleep(val);
    printf("%d ", val);
    fflush(stdout);
    return NULL;
}
void zapusk_6() {
    printf("\nзадание 6: Sleepsort\n");
    int arr[] = {4, 2, 19, 5, 18};
    int n = 5;
    pthread_t threads[n];
    printf("Сортировка чисел: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nРезультат: ");
    fflush(stdout);

    for (int i = 0; i < n; i++) {
        int* val = malloc(sizeof(int));
        *val = arr[i];
        pthread_create(&threads[i], NULL, sleepsort, val);
    }
    for (int i = 0; i < n; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("\n");
}
int main() {
    zapusk_12();   
    zapusk_3();     
    zapusk_45();   
    zapusk_6();     
    
    printf("\nПрограмма завершена.\n");
    return 0;
}
