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

// Function to insert node at the end of circular linked list
void insertNode(struct Node** head, int value) {
    struct Node* newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head; // Point to itself
        return;
    }

    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head; // Last node points back to head
}

// Function to traverse circular linked list
void traverseList(struct Node* head) {
    if (head == NULL) return;

    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

int main() {
    int n, i, value;
    struct Node* head = NULL;

    // Input number of nodes
    scanf("%d", &n);

    // Input elements and insert into circular linked list
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        insertNode(&head, value);
    }

    // Print circular linked list
    traverseList(head);

    return 0;
}
