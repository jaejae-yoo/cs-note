# Process

process는 컴퓨터 시스템의 작업단위(Task)이다. 프로그램이 메모리에 올라온 상태를 프로세스라하며, 어떤 프로그램이 프로세스가 되었다는 것은 운영체제로 부터 프로세스 제어 블록(PCB)를 받았다는 의미이다.

## Layout of process in memory
![image](https://user-images.githubusercontent.com/61091307/118851727-0a182500-b90d-11eb-8f49-312df0ecfeed.png)

    1. Text section 
        - 실행코드
    1. Data section
        - 전역 변수
    2. Heap section
       - 프로그램 실행중에 동적으로 할당되는 메모리
    3. Stack section
       - 함수를 호출할 때 임시 데이터 저장소 


## PCB (Process Control Block)
프로세스 제어 블록은 프로세스와 관련된 여러 정보들을 보관하는 자료구조이다. 

    1. process state 
        - new, ready, running, waiting, terminated
    2. program counter
        - 다음에 실행할 명령어의 주소를 가리킨다.
    3. cpu register 
    4. cpu scheduling information
        - 프로세스 우선순위, 스케줄 큐에 대한 포인터 등
    5. memory management information
    6. accounting information
        - CPU 사용시간과 시간제한 등
    7. I/O state information
        - 해당 프로세스에 할당된 입출력 장치들과 오픈된 파일들의 목록 등

## Process State

![image](https://user-images.githubusercontent.com/61091307/118853677-f7065480-b90e-11eb-9847-62b6d6037e28.png)

1. new


  프로세스가 메모리에 올라오고 운영체제로 부터 PCB를 부여받은 상태이다.

2. ready


 프로세스가 자신의 순서를 기다리는 상태로, PCB가 Ready Queue에서 기다리며 CPU scheduler에 의해 관리된다. CPU scheduler가 특정 프로세스를 선택하는 것을 dispatch라 한다.

3. running


프로세스가 CPU를 항당받아 실행되는 상태이다. 주어진 타임 슬라이스 동안만 작업을 할 수 있고, 시간을 모두 쓰면 timeout이 발생한다.

4. waiting


실행 상태에서 프로세스가 어떤 이벤트(입출력 등)가 발생하면 해당 이벤트가 완료될 때까지 기다리는 상태이다.   

5. terminated


프로세스가 종료되는 상태로 코드와 사용한 메모리를 삭제하고 PCB를 폐기한다.

# IPC(Inter-Process Communication)
1. shared memory
2. pipe

## Reference
Operating System Concepts, 10th Ed, Abraham Silberschatz