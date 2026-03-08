#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

// Enqueue operation
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (front == NULL) {
        front = newNode;
        rear = newNode;
        rear->next = front; // circular link
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front; // maintain circularity
    }
}

// Dequeue operation
void dequeue() {
    if (front == NULL) {
        return; // queue empty
    }

    if (front == rear) { // only one element
        free(front);
        front = NULL;
        rear = NULL;
    } else {
        struct Node* temp = front;
        front = front->next;
        rear->next = front; // maintain circularity
        free(temp);
    }
}

// Display queue
void display() {
    if (front == NULL) {
        return;
    }

    struct Node* temp = front;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
}

int main() {
    int n, m, i, val;
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(val);
    }

    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        dequeue();
    }

    display();
    return 0;
}
