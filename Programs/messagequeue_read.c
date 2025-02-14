#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define BUF_SIZE 100


struct mesg_buffer 
{
    long mesg_type;
    char mesg_text[BUF_SIZE];
} message;

int count_vowels(char* str)
{
    int count = 0;
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') 
            count++;
    }
    return count;
}

int main()
{
    key_t key;
    int msgid;
    key = ftok("progfile", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);
    msgrcv(msgid, &message, sizeof(message), 1, 0);
    printf("Message received : %s\n", message.mesg_text);
    printf("Number of vowels present: %d\n",count_vowels(message.mesg_text));
    msgctl(msgid, IPC_RMID, NULL);
    
    return 0;
}
