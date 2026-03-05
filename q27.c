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

// Function to calculate length of list
int getLength(struct Node* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

// Function to find intersection point
struct Node* getIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    // Advance longer list
    if (len1 > len2) {
        for (int i = 0; i < diff; i++) {
            head1 = head1->next;
        }
    } else {
        for (int i = 0; i < diff; i++) {
            head2 = head2->next;
        }
    }

    // Traverse both lists together
    while (head1 != NULL && head2 != NULL) {
        if (head1->data == head2->data) {
            return head1; // Intersection found
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL; // No intersection
}

int main() {
    int n, m, i, value;
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    // Input first list
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        insertNode(&list1, value);
    }

    // Input second list
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        scanf("%d", &value);
        insertNode(&list2, value);
    }

    // Find intersection
    struct Node* intersection = getIntersection(list1, list2);

    if (intersection != NULL)
        printf("%d\n", intersection->data);
    else
        printf("No Intersection\n");

    return 0;
}
