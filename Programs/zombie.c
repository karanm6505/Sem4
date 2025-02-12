#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t pid = fork();
    
    if(pid > 0) //Parent
    {
        sleep(50);
        printf("Parent pid: %d\n",getpid());
        printf("Child pid: %d\n",pid);
    }
    else if(pid == 0) //Child
    {
        printf("Child pid: %d\n",getpid());
    }
}