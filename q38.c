#include <stdio.h>
#include <stdlib.h>

#define MAX 100   // maximum size of deque

typedef struct {
    int arr[MAX];
    int front;
    int rear;
    int size;
} Deque;

// Initialize deque
void initDeque(Deque *dq) {
    dq->front = -1;
    dq->rear = -1;
    dq->size = 0;
}

// Check if empty
int empty(Deque *dq) {
    return dq->size == 0;
}

// Check size
int size(Deque *dq) {
    return dq->size;
}

// Insert at front
void push_front(Deque *dq, int value) {
    if (dq->size == MAX) {
        printf("Deque overflow!\n");
        return;
    }
    if (dq->front == -1) { // first element
        dq->front = dq->rear = 0;
    } else {
        dq->front = (dq->front - 1 + MAX) % MAX;
    }
    dq->arr[dq->front] = value;
    dq->size++;
}

// Insert at rear
void push_back(Deque *dq, int value) {
    if (dq->size == MAX) {
        printf("Deque overflow!\n");
        return;
    }
    if (dq->rear == -1) { // first element
        dq->front = dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % MAX;
    }
    dq->arr[dq->rear] = value;
    dq->size++;
}

// Remove from front
void pop_front(Deque *dq) {
    if (empty(dq)) {
        printf("Deque underflow!\n");
        return;
    }
    dq->front = (dq->front + 1) % MAX;
    dq->size--;
    if (dq->size == 0) dq->front = dq->rear = -1;
}

// Remove from rear
void pop_back(Deque *dq) {
    if (empty(dq)) {
        printf("Deque underflow!\n");
        return;
    }
    dq->rear = (dq->rear - 1 + MAX) % MAX;
    dq->size--;
    if (dq->size == 0) dq->front = dq->rear = -1;
}

// Get front element
int front(Deque *dq) {
    if (empty(dq)) {
        printf("Deque is empty!\n");
        return -1;
    }
    return dq->arr[dq->front];
}

// Get rear element
int back(Deque *dq) {
    if (empty(dq)) {
        printf("Deque is empty!\n");
        return -1;
    }
    return dq->arr[dq->rear];
}

// Clear deque
void clear(Deque *dq) {
    dq->front = dq->rear = -1;
    dq->size = 0;
}

// Display deque
void display(Deque *dq) {
    if (empty(dq)) {
        printf("Deque is empty!\n");
        return;
    }
    printf("Deque elements: ");
    int i = dq->front;
    for (int count = 0; count < dq->size; count++) {
        printf("%d ", dq->arr[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Example usage
int main() {
    Deque dq;
    initDeque(&dq);

    push_back(&dq, 10);
    push_back(&dq, 20);
    push_front(&dq, 5);
    display(&dq);

    printf("Front: %d\n", front(&dq));
    printf("Back: %d\n", back(&dq));

    pop_front(&dq);
    display(&dq);

    pop_back(&dq);
    display(&dq);

    clear(&dq);
    display(&dq);

    return 0;
}
