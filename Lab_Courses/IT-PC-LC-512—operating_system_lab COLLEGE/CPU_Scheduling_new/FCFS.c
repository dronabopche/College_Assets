#include <stdio.h>

struct Process {
    int pid, arrival, burst;
    int completion, turnaround, waiting;
};

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (int i = 0; i < n; i++) {
        printf("Enter PID, Arrival Time, Burst Time: ");
        scanf("%d %d %d", &p[i].pid, &p[i].arrival, &p[i].burst);
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

    int currentTime = 0;
    float totalTAT = 0, totalWT = 0;

    printf("\nGantt Chart:\n| ");

    for (int i = 0; i < n; i++) {

        if (currentTime < p[i].arrival) {
            while (currentTime < p[i].arrival) {
                printf("Idle | ");
                currentTime++;
            }
        }

        printf("P%d | ", p[i].pid);
        
        currentTime += p[i].burst;
        p[i].completion = currentTime;
        p[i].turnaround = p[i].completion - p[i].arrival;
        p[i].waiting = p[i].turnaround - p[i].burst;

        totalTAT += p[i].turnaround;
        totalWT += p[i].waiting;
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
