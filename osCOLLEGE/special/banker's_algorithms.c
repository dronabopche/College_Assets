#include <stdio.h>

int main() {
    int n, m;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resource types: ");
    scanf("%d", &m);

    int alloc[n][m], max[n][m], need[n][m], avail[m];
    int done[n], safeSeq[n];

    for (int i = 0; i < n; i++)
        done[i] = 0;

    printf("Enter Allocation Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Max Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("Enter Available Resources:\n");
    for (int i = 0; i < m; i++)
        scanf("%d", &avail[i]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    int completed = 0, idx = 0;

    while (completed < n) {
        int found = 0;

        for (int i = 0; i < n; i++) {
            if (!done[i]) {
                int canRun = 1;

                for (int j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        canRun = 0;
                        break;
                    }
                }

                if (canRun) {
                    for (int j = 0; j < m; j++)
                        avail[j] += alloc[i][j];

                    safeSeq[idx++] = i;
                    done[i] = 1;
                    completed++;
                    found = 1;
                }
            }
        }

        if (!found) {
            printf("\nSystem is NOT in safe state.\n");
            return 0;
        }
    }

    printf("\nSafe Sequence: ");
    for (int i = 0; i < n; i++)
        printf("P%d ", safeSeq[i]);

    printf("\n");
    return 0;
}
