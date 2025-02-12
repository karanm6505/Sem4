#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h> 
#include <unistd.h>

pthread_t tid1, tid2;
pthread_mutex_t first_mutex, second_mutex;

void *do_work_one(void *param)
{
    pthread_mutex_lock(&first_mutex);
    sleep(5);
    pthread_mutex_lock(&second_mutex);

    printf("Entering thread 1\n");
    sleep(5);
    printf("Exiting thread 1\n");

    pthread_mutex_unlock(&second_mutex);
    sleep(5);
    pthread_mutex_unlock(&first_mutex);
    pthread_exit(0);
}
void *do_work_two(void *param)
{
    pthread_mutex_lock(&second_mutex);
    sleep(5);
    pthread_mutex_lock(&first_mutex);

    printf("Entering thread 2\n");
    sleep(5);
    printf("Exiting thread 2\n");

    pthread_mutex_unlock(&first_mutex);
    sleep(5);
    pthread_mutex_unlock(&second_mutex);
    pthread_exit(0);
}
int main(void)
{
    int error;
    if(pthread_mutex_init(&first_mutex,NULL)!=0)
    {
        printf("\nFirst mutex initialisation has failed");
    }
    if(pthread_mutex_init(&second_mutex,NULL)!=0)
    {
        printf("\nSecond mutex initialisation has failed");
    }
}

