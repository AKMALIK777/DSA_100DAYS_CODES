#include <stdio.h>

int integerSqrt(int n) {
    if (n < 2) return n;   // sqrt(0)=0, sqrt(1)=1

    int low = 0, high = n, ans = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (mid * mid == n) {
            return mid;   // exact square root
        } else if (mid * mid < n) {
            ans = mid;    // possible answer
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", integerSqrt(n));
    return 0;
}
