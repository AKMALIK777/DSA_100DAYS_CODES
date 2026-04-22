#include <stdio.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_VOTES 1000

// Structure to hold candidate name and vote count
typedef struct {
    char name[MAX_NAME_LEN];
    int count;
} Candidate;

int main() {
    int n;
    scanf("%d", &n);

    Candidate candidates[MAX_VOTES];
    int candidateCount = 0;

    for (int i = 0; i < n; i++) {
        char vote[MAX_NAME_LEN];
        scanf("%s", vote);

        // Check if candidate already exists
        int found = 0;
        for (int j = 0; j < candidateCount; j++) {
            if (strcmp(candidates[j].name, vote) == 0) {
                candidates[j].count++;
                found = 1;
                break;
            }
        }

        // If not found, add new candidate
        if (!found) {
            strcpy(candidates[candidateCount].name, vote);
            candidates[candidateCount].count = 1;
            candidateCount++;
        }
    }

    // Find candidate with max votes
    char winner[MAX_NAME_LEN];
    int maxVotes = 0;

    for (int i = 0; i < candidateCount; i++) {
        if (candidates[i].count > maxVotes) {
            maxVotes = candidates[i].count;
            strcpy(winner, candidates[i].name);
        } else if (candidates[i].count == maxVotes) {
            // Tie case: choose lexicographically smaller
            if (strcmp(candidates[i].name, winner) < 0) {
                strcpy(winner, candidates[i].name);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}
