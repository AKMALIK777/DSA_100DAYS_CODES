#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Edge case: empty array
    if (n == 0) {
        return 0;
    }

    // Two-pointer approach
    int j = 0; // index for unique elements
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }

    // Print unique elements
    for (int i = 0; i <= j; i++) {
        printf("%d", arr[i]);
        if (i < j) printf(" ");
    }

    return 0;
}
