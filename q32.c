#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

// Push operation
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

// Pop operation
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    top--;  // just move top down
}

// Display remaining stack
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int n, m, value;

    // Input number of pushes
    scanf("%d", &n);

    // Push n elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        push(value);
    }

    // Input number of pops
    scanf("%d", &m);

    // Perform m pops
    for (int i = 0; i < m; i++) {
        pop();
    }

    // Display remaining stack
    display();

    return 0;
}
