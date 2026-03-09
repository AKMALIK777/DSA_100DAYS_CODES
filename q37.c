#include <stdio.h>
#define MAX 100

int pq[MAX];
int size = 0;

// Insert element into priority queue
void insert(int x) {
    if (size == MAX) {
        printf("Queue is full\n");
        return;
    }
    pq[size++] = x;
}

// Delete element with highest priority (smallest value)
int delete() {
    if (size == 0) return -1;

    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (pq[i] < pq[minIndex]) {
            minIndex = i;
        }
    }

    int deleted = pq[minIndex];

    // Shift elements left
    for (int i = minIndex; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }
    size--;

    return deleted;
}

// Peek element with highest priority
int peek() {
    if (size == 0) return -1;

    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (pq[i] < pq[minIndex]) {
            minIndex = i;
        }
    }
    return pq[minIndex];
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        char op[10];
        scanf("%s", op);

        if (op[0] == 'i') {   // insert
            int x;
            scanf("%d", &x);
            insert(x);
        } else if (op[0] == 'd') {  // delete
            int val = delete();
            printf("%d\n", val);
        } else if (op[0] == 'p') {  // peek
            int val = peek();
            printf("%d\n", val);
        }
    }
    return 0;
}
