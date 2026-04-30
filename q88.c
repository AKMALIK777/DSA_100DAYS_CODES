#include <stdio.h>
#include <stdlib.h>

// Comparator for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Function to check if cows can be placed with at least 'dist' apart
int canPlaceCows(int stalls[], int n, int k, int dist) {
    int count = 1; // place first cow at stalls[0]
    int lastPos = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - lastPos >= dist) {
            count++;
            lastPos = stalls[i];
            if (count == k) return 1; // placed all cows
        }
    }
    return 0;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int stalls[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &stalls[i]);
    }

    // Step 1: Sort stall positions
    qsort(stalls, n, sizeof(int), compare);

    // Step 2: Binary search on distance
    int low = 1;
    int high = stalls[n-1] - stalls[0];
    int ans = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (canPlaceCows(stalls, n, k, mid)) {
            ans = mid;       // feasible, try larger
            low = mid + 1;
        } else {
            high = mid - 1;  // not feasible, try smaller
        }
    }

    printf("%d\n", ans);
    return 0;
}
