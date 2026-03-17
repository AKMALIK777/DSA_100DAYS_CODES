#include <stdio.h>
#include <stdlib.h>

// Node structure for queue
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Queue structure
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Stack structure
typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

// Queue functions
void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeue(Queue* q) {
    if (q->front == NULL) return -1;
    Node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return value;
}

int isEmptyQueue(Queue* q) {
    return q->front == NULL;
}

// Stack functions
void push(StackNode** top, int value) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

int pop(StackNode** top) {
    if (*top == NULL) return -1;
    StackNode* temp = *top;
    int value = temp->data;
    *top = (*top)->next;
    free(temp);
    return value;
}

int isEmptyStack(StackNode* top) {
    return top == NULL;
}

// Reverse queue using stack
void reverseQueue(Queue* q) {
    StackNode* stack = NULL;
    while (!isEmptyQueue(q)) {
        push(&stack, dequeue(q));
    }
    while (!isEmptyStack(stack)) {
        enqueue(q, pop(&stack));
    }
}

// Print queue
void printQueue(Queue* q) {
    Node* temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Driver program
int main() {
    int N;
    scanf("%d", &N);

    Queue q;
    initQueue(&q);

    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        enqueue(&q, x);
    }

    reverseQueue(&q);

    printQueue(&q);

    return 0;
}
