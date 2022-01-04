# Step
![image](https://user-images.githubusercontent.com/61091307/147923233-13836b9d-353c-4cd3-bb78-3e7bd752054e.png)
###### 출처: git-scm (Git 기초)

### 수행 과정 
1. **Working tree**에서 파일을 수정한다.
2. **Staging Area**에 commit할 스냅샷들을 생성한다.
3. Stagin Arad에 존재하는 파일들을  **Git directory**에 commit한다. 

- checkout 명령어를 통해 원하는 버전으로 돌아갈 수 있다.

- git directory에 commit한 것은 local에 존재하는 것이기 때문에, remote repository에 저장해야 한다.

# Status
![image](https://user-images.githubusercontent.com/61091307/147926123-9d30ece4-8245-41ac-a44a-94629b2017cd.png)
###### 출처: git-scm (Git 기초)

working directory의 파일은 **Tracked**와 **Untracked**로 나뉘게 된다. 

- Tracked: git이 관리하고 있는 파일.
- Untraked: git이 관리하고 있지 않는 파일. 

Tracked된 파일은 **Unmodified, Modified, Staged** 상태 중 하나이다.

- 파일은 수정하면 Modified 상태가 되고, commit하기 위해 staged 상태를 만든(add) 후 commit 하게 된다.

- - -
## Reference
[Git SCM](https://git-scm.com/book/ko/v2)