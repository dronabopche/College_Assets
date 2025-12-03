#include <stdio.h>

struct Process {
    int pid, arrival, burst;
    int remaining;
    int completion, turnaround, waiting;
};

int main() {
    int n, tq;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (int i = 0; i < n; i++) {
        printf("Enter PID, Arrival Time, Burst Time: ");
        scanf("%d %d %d", &p[i].pid, &p[i].arrival, &p[i].burst);
        p[i].remaining = p[i].burst;
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    int time = 0, completed = 0;
    float totalTAT = 0, totalWT = 0;

    int queue[100], front = 0, rear = 0;
    int visited[n];

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nGantt Chart:\n| ");

    for (int i = 0; i < n; i++) {
        if (p[i].arrival == time) {
            queue[rear++] = i;
            visited[i] = 1;
        }
    }

    while (completed < n) {
        if (front == rear) {
            printf("Idle | ");
            time++;

            for (int i = 0; i < n; i++) {
                if (!visited[i] && p[i].arrival <= time) {
                    queue[rear++] = i;
                    visited[i] = 1;
                }
            }
            continue;
        }

        int idx = queue[front++];
        printf("P%d | ", p[idx].pid);

        int exec = (p[idx].remaining > tq) ? tq : p[idx].remaining;

        p[idx].remaining -= exec;
        time += exec;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && p[i].arrival <= time) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }

        if (p[idx].remaining > 0) {
            queue[rear++] = idx;
        } else {
            completed++;
            p[idx].completion = time;
            p[idx].turnaround = p[idx].completion - p[idx].arrival;
            p[idx].waiting = p[idx].turnaround - p[idx].burst;

            totalTAT += p[idx].turnaround;
            totalWT += p[idx].waiting;
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
