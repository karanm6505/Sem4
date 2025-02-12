#define BUFFER_SIZE 100
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>      // Add this header for O_WRONLY
#include <string.h>
#include <sys/stat.h>
int main()
{
    int fd;
    char buff[BUFFER_SIZE] = "";

    //FIFO file path
   char myfifo[BUFFER_SIZE] = "/tmp/myfifo";
   printf("Enter the message to be passed\n");
   read(0,buff,BUFFER_SIZE);

   //Create a named file(FIFO)
   mkfifo(myfifo,0666);

   fd = open(myfifo, O_WRONLY) ;

   write(fd,buff,strlen(buff)+1);
   close(fd);
   
   sleep(10);
   return 0;
}