#include <stdio.h>

struct Process {
    int pid, arrival, burst;
    int remaining;
    int completion, turnaround, waiting;
    int done;
};

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (int i = 0; i < n; i++) {
        printf("Enter PID, Arrival, Burst: ");
        scanf("%d %d %d", &p[i].pid, &p[i].arrival, &p[i].burst);
        p[i].remaining = p[i].burst;
        p[i].done = 0;
    }

    int completed = 0, currentTime = 0;
    float totalTAT = 0, totalWT = 0;

    printf("\nGantt Chart:\n| ");

    while (completed < n) {
        int idx = -1;
        int minRem = 99999;

        for (int i = 0; i < n; i++) {
            if (!p[i].done && p[i].arrival <= currentTime) {
                if (p[i].remaining < minRem) {
                    minRem = p[i].remaining;
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            printf("Idle | ");
            currentTime++;
        } else {
            printf("P%d | ", p[idx].pid);
            p[idx].remaining--;
            currentTime++;

            if (p[idx].remaining == 0) {
                p[idx].done = 1;
                completed++;
                p[idx].completion = currentTime;
                p[idx].turnaround = p[idx].completion - p[idx].arrival;
                p[idx].waiting = p[idx].turnaround - p[idx].burst;
                totalTAT += p[idx].turnaround;
                totalWT += p[idx].waiting;
            }
        }
    }

    printf("\n\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
            p[i].pid, p[i].arrival, p[i].burst,
            p[i].completion, p[i].turnaround, p[i].waiting);
    }

    printf("\nAverage Turnaround Time = %.2f\n", totalTAT / n);
    printf("Average Waiting Time = %.2f\n", totalWT / n);

    return 0;
}
