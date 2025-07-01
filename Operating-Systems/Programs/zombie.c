#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid > 0) {  // Parent process
        printf("Parent (PID: %d), Child (PID: %d) created.\n", getpid(), pid);
        sleep(10);  // Sleep without calling wait(), keeping child as a zombie
    } else if (pid == 0) {  // Child process
        printf("Child (PID: %d) exiting...\n", getpid());
        exit(0);  // Child terminates, becomes a zombie
    }

    return 0;
}
