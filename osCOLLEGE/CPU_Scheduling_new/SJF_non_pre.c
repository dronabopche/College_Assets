#include <stdio.h>

struct Process {
    int pid, arrival, burst;
    int completion, turnaround, waiting;
    int done;
};

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (int i = 0; i < n; i++) {
        printf("Enter PID, Arrival Time, Burst Time: ");
        scanf("%d %d %d", &p[i].pid, &p[i].arrival, &p[i].burst);
        p[i].done = 0;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].arrival > p[j+1].arrival) {
                struct Process t = p[j];
                p[j] = p[j+1];
                p[j+1] = t;
            }
        }
    }

    int currentTime = 0, completed = 0;
    float totalTAT = 0, totalWT = 0;

    printf("\nGantt Chart:\n| ");

    while (completed < n) {

        int idx = -1;
        int minBurst = 99999;

        for (int i = 0; i < n; i++) {
            if (!p[i].done && p[i].arrival <= currentTime) {
                if (p[i].burst < minBurst) {
                    minBurst = p[i].burst;
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            printf("Idle | ");
            currentTime++;
        } else {
            printf("P%d | ", p[idx].pid);

            currentTime += p[idx].burst;
            p[idx].completion = currentTime;
            p[idx].turnaround = p[idx].completion - p[idx].arrival;
            p[idx].waiting = p[idx].turnaround - p[idx].burst;

            totalTAT += p[idx].turnaround;
            totalWT += p[idx].waiting;

            p[idx].done = 1;
            completed++;
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
