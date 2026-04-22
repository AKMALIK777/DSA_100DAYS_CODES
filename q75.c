#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Hash map node
typedef struct Node {
    int sum;
    int index;
    struct Node* next;
} Node;

// Hash function
int hash(int sum, int size) {
    if (sum < 0) sum = -sum;
    return sum % size;
}

// Insert into hash map
void insert(Node* hashTable[], int size, int sum, int index) {
    int h = hash(sum, size);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->sum = sum;
    newNode->index = index;
    newNode->next = hashTable[h];
    hashTable[h] = newNode;
}

// Search in hash map
int search(Node* hashTable[], int size, int sum) {
    int h = hash(sum, size);
    Node* temp = hashTable[h];
    while (temp) {
        if (temp->sum == sum) return temp->index;
        temp = temp->next;
    }
    return -1;
}

int longestZeroSumSubarray(int arr[], int n) {
    int maxLen = 0;
    int sum = 0;
    int size = n * 2; // hash table size
    Node* hashTable[size];
    for (int i = 0; i < size; i++) hashTable[i] = NULL;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0) {
            if (i + 1 > maxLen) maxLen = i + 1;
        }

        int prevIndex = search(hashTable, size, sum);
        if (prevIndex != -1) {
            if (i - prevIndex > maxLen) maxLen = i - prevIndex;
        } else {
            insert(hashTable, size, sum, i);
        }
    }

    return maxLen;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = longestZeroSumSubarray(arr, n);
    printf("%d\n", result);

    return 0;
}
