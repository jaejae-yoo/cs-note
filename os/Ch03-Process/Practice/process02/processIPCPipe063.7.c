#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

/* IPC mechanism : Ordinary Pipe */

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main() {
    char write_msg[BUFFER_SIZE]="IPC mechanism : Pipe";
    char read_msg[BUFFER_SIZE];
    int fd[2];  // two way (양방향)  
    pid_t pid;

    /* create pipe */
    pipe(fd);

    /* parent process와 child process 통신*/
    pid = fork(); // fork a new process

    if (pid > 0) { // parent process
        close(fd[READ_END]); //write만 하므로 
        
        /* write to the pipe */
        write(fd[WRITE_END], write_msg, strlen(write_msg) + 1);
        close(fd[WRITE_END]);
    }

    else if (pid == 0) { // child process
        close(fd[WRITE_END]); //read만 하므로 

        /* read to the pipe */
        read(fd[READ_END], read_msg, BUFFER_SIZE);
        printf("read %s\n", read_msg);
        close(fd[READ_END]);
    }
    
    return 0;
}