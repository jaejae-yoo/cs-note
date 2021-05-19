#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main(){
    pid_t pid, pid1;
    pid = fork();
    // fork 호출이 성공하여 자식 프로세스가 만들어지면 부모 프로세스에서는 자식 프로세스의 프로세스 ID가 반환되고 자식 프로세스에서는 0을 반환한다.
    if (pid == 0){      //child process
        pid1 = getpid();
        printf("child: pid = %d\n", pid);
        printf("child: pid1 = %d\n", pid1); 
    }
    else if (pid > 0){   //parent process
        wait(NULL);
        pid1 = getpid();
        printf("parent: pid = %d\n", pid);  //child pid
        printf("parent: pid1 = %d\n", pid1); //parent pid
    }
    return 0;
}