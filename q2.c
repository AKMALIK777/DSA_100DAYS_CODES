#include <stdio.h>

int main() {
    int n, pos;
    
    // Read size of array
    scanf("%d", &n);
    
    int arr[n];
    
    // Read array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Read position to delete (1-based)
    scanf("%d", &pos);
    
    // Validate position
    if (pos < 1 || pos > n) {
        printf("Invalid position\n");
        return 0;
    }
    
    // Shift elements to the left
    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    // Print updated array
    for (int i = 0; i < n - 1; i++) {
        printf("%d", arr[i]);
        if (i < n - 2) printf(" ");
    }
    
    return 0;
}
