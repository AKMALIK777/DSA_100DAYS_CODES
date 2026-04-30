#include <stdio.h>

// Function to check if allocation is possible
int isPossible(int books[], int n, int m, int maxPages) {
    int students = 1;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (books[i] > maxPages) return 0; // single book exceeds limit

        if (sum + books[i] > maxPages) {
            students++;
            sum = books[i];
            if (students > m) return 0;
        } else {
            sum += books[i];
        }
    }
    return 1;
}

int allocateBooks(int books[], int n, int m) {
    int low = books[0], high = 0;
    for (int i = 0; i < n; i++) {
        if (books[i] > low) low = books[i]; // max single book
        high += books[i];                   // total sum
    }

    int ans = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (isPossible(books, n, m, mid)) {
            ans = mid;
            high = mid - 1; // try smaller maximum
        } else {
            low = mid + 1;  // increase limit
        }
    }
    return ans;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int books[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &books[i]);
    }

    int result = allocateBooks(books, n, m);
    printf("%d\n", result);

    return 0;
}
