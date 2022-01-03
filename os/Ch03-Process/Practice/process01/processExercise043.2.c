#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main() {
    //초기 : Process1
    fork(); //존재하는 Process 총 2개: Process1, Process2 
    fork(); //존재하는 Process 총 4개: (Process1, Process2), Process3, Process4
    fork(); //존재하는 Process 총 8개: (Process1, Process2 , Process3, Process4), (Process5, Process6 , Process7, Process8)

    //결론: fork()로 인한 프로세스의 갯수는 n개의 fork()가 있을 때, 2^n개의 프로세스가 생성된다.
    printf("Hello fork()\n");
    return 0;
}