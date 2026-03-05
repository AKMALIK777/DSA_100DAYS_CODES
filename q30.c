#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert node at the end of list
void insertNode(struct Node** head, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
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

// Function to print polynomial in standard form
void printPolynomial(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->coeff);
        if (temp->exp > 1) {
            printf("x^%d", temp->exp);
        } else if (temp->exp == 1) {
            printf("x");
        }
        if (temp->next != NULL) {
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, coeff, exp;
    struct Node* head = NULL;

    // Input number of terms
    scanf("%d", &n);

    // Input coefficient and exponent pairs
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        insertNode(&head, coeff, exp);
    }

    // Print polynomial
    printPolynomial(head);

    return 0;
}
