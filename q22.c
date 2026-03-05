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

// Function to traverse and print the linked list
void traverseList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Function to count nodes in the linked list
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    int n, i, value;
    struct Node *head = NULL, *tail = NULL;

    // Input size of linked list
    scanf("%d", &n);

    // Input elements and create linked list
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        struct Node* newNode = createNode(value);

        if (head == NULL) {
            head = newNode;   // First node
            tail = newNode;
        } else {
            tail->next = newNode; // Link new node
            tail = newNode;
        }
    }

    // Output linked list
    traverseList(head);

    // Print node count
    printf("\nTotal nodes = %d\n", countNodes(head));

    return 0;
}
