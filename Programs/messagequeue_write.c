#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX 10
#define BUF_SIZE 100

struct mesg_buffer 
{
   long mesg_type;
   char mesg_text[BUF_SIZE];
} message;

int main()
{
    key_t key;
    int msgid;
    FILE *fp;

    fp = fopen("input.txt", "r");
    if (fp == NULL) 
    {
        printf("Error opening file!\n");
        return 1;
    }

    fgets(message.mesg_text, BUF_SIZE, fp);
    fclose(fp);

    printf("Message being sent: %s\n", message.mesg_text);
    key = ftok("progfile", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);
    message.mesg_type = 1;
    msgsnd(msgid, &message, sizeof(message), 0);

    sleep(60);
    return 0;
}
