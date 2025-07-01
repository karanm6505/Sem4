#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int pid = fork();

    if(pid > 0)
    {
        printf("In parent process - PID: %d\n", getpid());
        exit(0);
    }
    else if(pid == 0)
    {
        sleep(30);
        printf("In child process - PID: %d\t Parent process - PID: %d\n", getpid(),getppid());
    }
    return 0;
}