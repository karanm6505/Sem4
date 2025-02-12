#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    char filename[256];
    pid_t pid;
    int status;


    printf("Enter the filename: ");
    scanf("%s", filename);

   
    pid = fork();

    if (pid < 0) 
    {
        
        fprintf(stderr, "Fork failed\n");
        exit(1);
    }
    else if (pid == 0) 
    {
        // Child process
        printf("Child Process ID: %d\n", getpid());
        execlp("wc", "wc", "-w", filename, NULL);
        fprintf(stderr, "Failed to execute wc\n");
        exit(1);
    }
    else
    {
       
        printf("Parent Process ID: %d\n", getpid());
        wait(&status);
        printf("Child process completed\n");
    }

    return 0;
}
