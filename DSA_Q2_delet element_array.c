#include <stdio.h>

int main() {
    int n, pos;
    
    // Step 1: Input size
    scanf("%d", &n);
    
    int arr[100]; // assuming max size 100
    
    // Step 2: Input array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Step 3: Input position (1-based)
    scanf("%d", &pos);
    
    // Validate position
    if (pos < 1 || pos > n) {
        printf("Invalid position\n");
        return 0;
    }
    
    // Step 4: Shift elements to the left
    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    n--; // array size decreases
    
    // Step 5: Print updated array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
