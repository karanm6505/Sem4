#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h> //POSIX threads

int g = 0; //global var
void *myThreadFunction(void *vargp)
{
    int *myid = (int *)vargp; //store value arg passed to the thread
    static int s = 0; // static var to observe changes
    int l = 0; //local var to observe changes
    ++l, ++s, ++g; //change global,static,local vars
    printf("Thread ID: %d, Local: %d, Static: %d, Global: %d\n",*myid,l,s,g);
    pthread_exit(NULL);
}
int main()
{
    int i;
    pthread_t tid;

    for(int i = 0; i<3; i++)
    {
        pthread_create(&tid, NULL, myThreadFunction, (void *)(&tid));
        pthread_join(tid,NULL);
    }
    printf("In main()\n");
    return 0;

}