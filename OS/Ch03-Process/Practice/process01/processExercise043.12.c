#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main() {
    pid_t pid;
    pid = fork();

    if (pid ==0){
        execlp("/bin/ls", "ls", NULL);
        printf("Line J\n");       // ls process로 변경했기 때문에 LIne J가 출력되지 않는다.
    }
    else if (pid > 0){
        wait(NULL);
        printf("Child Complete\n");
    }
    return 0;
}