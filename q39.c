#include <stdio.h>
#include <stdlib.h>

#define MAX 1000   // maximum size of heap

typedef struct {
    int arr[MAX];
    int size;
} MinHeap;

// Initialize heap
void initHeap(MinHeap *h) {
    h->size = 0;
}

// Swap helper
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up (for insert)
void heapifyUp(MinHeap *h, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (h->arr[parent] > h->arr[index]) {
            swap(&h->arr[parent], &h->arr[index]);
            index = parent;
        } else break;
    }
}

// Heapify down (for extractMin)
void heapifyDown(MinHeap *h, int index) {
    int left, right, smallest;
    while (1) {
        left = 2 * index + 1;
        right = 2 * index + 2;
        smallest = index;

        if (left < h->size && h->arr[left] < h->arr[smallest])
            smallest = left;
        if (right < h->size && h->arr[right] < h->arr[smallest])
            smallest = right;

        if (smallest != index) {
            swap(&h->arr[index], &h->arr[smallest]);
            index = smallest;
        } else break;
    }
}

// Insert element
void insert(MinHeap *h, int value) {
    if (h->size == MAX) {
        printf("Heap overflow!\n");
        return;
    }
    h->arr[h->size] = value;
    heapifyUp(h, h->size);
    h->size++;
}

// Peek (minimum element)
int peek(MinHeap *h) {
    if (h->size == 0) return -1;
    return h->arr[0];
}

// Extract minimum
int extractMin(MinHeap *h) {
    if (h->size == 0) return -1;
    int min = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;
    heapifyDown(h, 0);
    return min;
}

// Driver program
int main() {
    int N;
    scanf("%d", &N);

    MinHeap h;
    initHeap(&h);

    for (int i = 0; i < N; i++) {
        char op[20];
        scanf("%s", op);

        if (strcmp(op, "insert") == 0) {
            int x;
            scanf("%d", &x);
            insert(&h, x);
        }
        else if (strcmp(op, "peek") == 0) {
            int val = peek(&h);
            printf("%d\n", val);
        }
        else if (strcmp(op, "extractMin") == 0) {
            int val = extractMin(&h);
            printf("%d\n", val);
        }
    }

    return 0;
}
