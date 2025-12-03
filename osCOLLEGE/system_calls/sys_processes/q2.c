#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid == 0) {
        execlp("date", "date", NULL);
    } 
    else {
        wait(NULL);
        printf("Parent PID: %d, Child PID: %d\n", getpid(), pid);
    }

    return 0;
}
