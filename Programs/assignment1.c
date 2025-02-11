#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    char filename[256];
    pid_t pid;
    int status;

    printf("Enter filename:\n");
    scanf("%s", filename);

    pid = fork();
    if (pid < 0)
    {
        fprintf(stderr, "Fork was unsuccessful\n");
        exit(1);
    }
    else if (pid == 0)
    {
        // Child process
        printf("Child Process ID: %d\n", getpid());
        char *args[] = {"wc", "-w", filename, NULL};
        execvp("wc", args);
        fprintf(stderr, "Failed to execute wc\n");
        exit(1);
    }
    else
    {
        // Parent process
        printf("Parent Process ID: %d\n", getpid());
        printf("Child Process ID: %d\n", pid); // Print child process ID
        wait(&status);
        printf("Child process completed\n");
    }

    return 0;
}

