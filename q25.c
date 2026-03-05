#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert node at the end of a list
void insertNode(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to count occurrences of key
int countOccurrences(struct Node* head, int key) {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            count++;
        }
        temp = temp->next;
    }
    return count;
}

int main() {
    int n, i, value, key;
    struct Node* head = NULL;

    // Input number of nodes
    scanf("%d", &n);

    // Input elements
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        insertNode(&head, value);
    }

    // Input key to count
    scanf("%d", &key);

    // Count occurrences
    int result = countOccurrences(head, key);

    // Print result
    printf("%d\n", result);

    return 0;
}
