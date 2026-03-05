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

// Function to insert node at the end of list
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

// Function to rotate list right by k places
struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0) return head;

    // Find length and last node
    int length = 1;
    struct Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
        length++;
    }

    // Make list circular
    tail->next = head;

    // Effective rotations
    k = k % length;
    int stepsToNewHead = length - k;

    // Find new head
    struct Node* newTail = head;
    for (int i = 1; i < stepsToNewHead; i++) {
        newTail = newTail->next;
    }
    struct Node* newHead = newTail->next;

    // Break the circle
    newTail->next = NULL;

    return newHead;
}

// Function to print list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n, i, value, k;
    struct Node* head = NULL;

    // Input number of nodes
    scanf("%d", &n);

    // Input elements
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        insertNode(&head, value);
    }

    // Input k
    scanf("%d", &k);

    // Rotate list
    head = rotateRight(head, k);

    // Print rotated list
    printList(head);

    return 0;
}
