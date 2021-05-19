#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();
    // parent process PID != 0   /  child process PID == 0
    printf("Hello Process! %d\n", pid);
    
    return 0;
}