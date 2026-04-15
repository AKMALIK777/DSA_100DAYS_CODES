#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int seen[26] = {0};  // track occurrences of lowercase letters

    for (int i = 0; i < strlen(s); i++) {
        int idx = s[i] - 'a';
        if (seen[idx] == 1) {
            // second occurrence found
            printf("%c\n", s[i]);
            return 0;
        }
        seen[idx] = 1;
    }

    // if no repeated character
    printf("-1\n");
    return 0;
}
