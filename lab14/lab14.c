#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct room {
 char name[50]; // имя комнаты
 int level; // уровень/сложность комнаты
 int number; // номер комнаты
 int resolution; // размер комнаты
};

struct node {
    struct room data;
    struct node *next;
};

typedef struct node node_t;

node_t *NewNode(struct room data) {

    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

node_t* append(node_t** head, struct room data) {
    node_t* new_node = NewNode(data);
    if (new_node == NULL) {
        return *head;
    }
    if (*head == NULL) {
        *head = new_node;
        return new_node;
    }
    node_t* cur = *head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = new_node;
    return *head;
}

void printList(node_t *head) {

    node_t* cur = head;
    while (cur) {
        printf("Имя: %s, Уровень: %d, Номер комнаты: %d, Размер команты: %d\n",
        cur->data.name, cur->data.level, cur->data.number,cur->data.resolution);
        cur = cur->next;
    }
    printf("NULL\n");
}

void freelist(struct node* head) {
    struct node *temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n, i;
    struct node *head = NULL;
    char *names[] = {"Логово", "Святилище", "Сокровищница", "Кузница", "Алтарь", "Западня", "Лавка", "Костяк", "Бездна", "Портал"};

    srand(time(NULL));

    printf("Enter n: ");
    scanf("&d", &n);

    for (i=0; i < n; i++) {
        struct room r;

        strcpy(r.name, names[rand() % 10]);
        r.level = rand() % 10 + 1;
        r.number = i + 1;
        r.resolution = rand() % 100 + 1;

        append(&head, r);

    }

    printList(head);
    freeList(head);

    return 0;
}
