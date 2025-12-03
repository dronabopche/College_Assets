#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t c1, c2;

    c1 = fork();  // First child
    if (c1 == 0) {
        printf("Child 1: PID = %d, PPID = %d\n", getpid(), getppid());
        return 0;
    } 
    else {
        c2 = fork();  // Second child
        if (c2 == 0) {
            printf("Child 2: PID = %d, PPID = %d\n", getpid(), getppid());
            return 0;
        } 
        else {
            // Parent waits for both children
            wait(NULL);
            wait(NULL);
            printf("Parent: PID = %d\n", getpid());
        }
    }

    return 0;
}
