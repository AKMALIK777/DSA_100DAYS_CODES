#include <stdio.h>
#include <stdlib.h>

#define EMPTY -1

int m;          // size of hash table
int *table;     // hash table array

// Basic hash function
int hash(int key) {
    return key % m;
}

// Insert using quadratic probing
void insert(int key) {
    int h = hash(key);
    for (int i = 0; i < m; i++) {
        int pos = (h + i*i) % m;
        if (table[pos] == EMPTY) {
            table[pos] = key;
            return;
        }
    }
    // If table is full, insertion fails
}

// Search using quadratic probing
int search(int key) {
    int h = hash(key);
    for (int i = 0; i < m; i++) {
        int pos = (h + i*i) % m;
        if (table[pos] == EMPTY) {
            return 0; // not found
        }
        if (table[pos] == key) {
            return 1; // found
        }
    }
    return 0;
}

int main() {
    int q;
    scanf("%d", &m);   // table size
    scanf("%d", &q);   // number of operations

    table = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }

    for (int i = 0; i < q; i++) {
        char op[10];
        int key;
        scanf("%s %d", op, &key);

        if (op[0] == 'I') { // INSERT
            insert(key);
        } else if (op[0] == 'S') { // SEARCH
            if (search(key))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    free(table);
    return 0;
}
