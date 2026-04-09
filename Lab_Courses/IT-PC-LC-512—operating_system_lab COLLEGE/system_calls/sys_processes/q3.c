#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t c1, c2;

    c1 = fork();
    if (c1 == 0) {
        // First child: display current directory contents
        execlp("ls", "ls", NULL);
    } 
    else {
        c2 = fork();
        if (c2 == 0) {
            // Second child: display process information
            execlp("ps", "ps", NULL);
        } 
        else {
            // Parent waits for both
            wait(NULL);
            wait(NULL);
            printf("Parent PID: %d, Child1 PID: %d, Child2 PID: %d\n", getpid(), c1, c2);
        }
    }
    return 0;
}
