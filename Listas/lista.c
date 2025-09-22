#include <stdio.h> 
#include <stdlib.h>

struct Node {
    int data; // 4 bytes
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Error: memoria no reservada");
        exit(1);
    }
    
    
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
};

int main() {
    struct Node* head = createNode(10);
    struct Node* current = head;

    // Crear 999 nodos adicionales (en total serán 1000)
    for (int i = 1; i < 100000000; i++) {
        struct Node* newNode = createNode(10 + i);
        current->next = newNode;
        current = newNode;
    }

    printList(head);

    // Liberar memoria
    current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}