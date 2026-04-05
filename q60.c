#include <stdio.h>
#include <stdlib.h>

// Function to check Min-Heap property
int isMinHeap(int arr[], int n) {
    // For every parent node, check its children
    for (int i = 0; i <= (n - 2) / 2; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // Check left child
        if (left < n && arr[i] > arr[left]) return 0;

        // Check right child
        if (right < n && arr[i] > arr[right]) return 0;
    }
    return 1;
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    if (isMinHeap(arr, N))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
