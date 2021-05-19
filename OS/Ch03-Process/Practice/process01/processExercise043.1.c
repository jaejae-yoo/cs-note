#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int value = 5;

int main() {
    pid_t pid;
    pid = fork();

    if (pid == 0){
        value += 15;
        return 0;
    }
    else if (pid > 0){
        wait(NULL);
        printf("Parent: value = %d\n", value); // value = 5. child의 process value 값은 parent process에 영향 X
    }
}