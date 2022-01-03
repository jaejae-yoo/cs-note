# CPU Scheduling

## 1. Preemptive Scheduling (선점형 스케줄링)

어떤 프로세스가 CPU를 할당받아 실행중이더라도 OS가 CPU를 강제로 뺏을 수 있는 (해당 프로세스를 쫓아낼 수 있는) 스케줄링 방식

## 2. Non-preemptive Scheduling (비선점형 스케줄링)

어떤 프로세스가 CPU를 점유하면 다른 프로세스가 빼앗을 수 있는 스케줄링 방식(자발적으로 빠져나오는 것만 가능)

## Decision making for cpu-scheduling
1. running state ➔ waiting state (ex. I/O 요청)
2. running state ➔ ready state (ex. interrupt)
3. waitting state ➔ ready state (ex. I/O 종료)
4. process terminate

➔ 1, 4 : non-preemptive

➔ 2, 3 : preemptive or non-preemptive

- - -

## Dispatcher 
dispatcher는 CPU 코어의 제어를 CPU 스케줄러가 선택한 프로세스에게 주는 모듈이다. 

디스패처의 역할: 

1. 프로세스간의 문맥 교환
2. user mode로  전환
3. 프로그램을 다시 시작하기 위한 적절한 위치로 jump

즉, sheduler는 어떤 프로세스로 변경할지 선택하고 실제로 swiching하는 것은 dispatcher

dispatcher latency : 디스패처가 하나의 프로세스를 중단하고 다른 프로세스의 수행을 시작하는데까지 소요되는 시간

- - -

## CPU Criteria
1. CPU utilization

CPU가 가능한 최대한 바쁘게 작업을 수행하는지

2. Throwghput

단위 시간당 수행이 완료된 프로세스의 개수

3. Turnaround time

프로세스를 실행하는데 소요된 시간

4. waiting time

프로세스가 ready queue에 대기한 시간

5. Response time
응답이 시작되는 때까지 걸린 시간

- - -

## CPU Scheduling Problem
ready queue에 존재하는 어떤 프로세스에 CPU Core을 할당할 것인지


## Scheduling Algorithm

1. FCFS (First-Come, First-Served)

ready queue에 도착한 순서대로 CPU를 할당하는 비선점형 방식

2. SJF (Shotest-Job-First)

ready queue에 있는 프로세스 중에서 CPU burst가 작은 순서대로 CPU를 할당하는 비선점형 방식
만약, 같은 CPU burst를 가지면 FCFS 스케줄링을 적용한다.

➔ 문제점: next CPU curst time을 어떻게 알 것인가 ? 

해결방법: 과거에 수행한 해당 프로세스의 CPU burst를 지수적 평균으로 구한다.


3. SRT(Shortes Remaining Time)

기본적으로 라운드 로빈 스케줄링을 사용하지만 CPU를 할당할 프로세스는 남아 있는 작업 시간이 가장 적은 프로세스로 선택한다.

➔ 문제점: remain time을 계속 계산해야 함

4. RR(Round Robin)

한 프로세스가 할당받은 타임슬라이스(time slice or time quantum)동안 작업을 수행하다가, 주어진 time slice안에 완료하지 못하면 ready queue의 맨 뒤로 가서 순서를 기다리는 방식이다. 
    
    2.1 CPU burst가 하나의 time slice보다 작은 경우
        프로세스 자신이 자발적으로 CPU를 방출
    2.2 CPU burst가 하나의 time slice보다 긴 경우
        timer가 끝나고 운영체제에 interrupt를 방생하면 context switch가 발생하고 ready queue 꼬리에 삽입된다. 
        그 후 CPU 스케줄러는 다음 프로세스를 선택한다.

5. Priority

우선 순위가 높은 프로세스부터 CPU 할당

➔ 문제점: starvation problem 
    
해결방법: aging : 오래 대기하고 있으면 우선순위를 점진적으로 높임


6. MLQ(Multilevel Queue Scheduling)

priority 각각에 ready queue를 부여하는 방식

7. MLFQ(Multilevel Feedback Queue Scheduling)

time slice를 priority마다 다르게 부여하는 방식

- - -

## Reference
Operating System Concepts, 10th Ed, Abraham Silberschatz