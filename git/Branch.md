# Branch
브랜치를 통해 독립적인 개발을 할 수 있다.

    git branch testing
    
먼저 testing이라는 새 브랜치를 생성했다고 가정해서 설명하면, 
![image](https://user-images.githubusercontent.com/61091307/148012330-50588368-8356-4428-a4a7-a6c4507f29e9.png)
###### 출처: git-scm (Git 브랜치)

새로 생성한 testing 브랜티도 마지막 커밋을 가리키고 있다.

HEAD는 현재 작업중인 브랜치(master)를 가리키는 포인터이다. 

    git checkout testing

명령어를 입력하면, HEAD가 testing 브랜치를 가리키게 된다.

- - -

## 1. Merge

![image](https://user-images.githubusercontent.com/61091307/148014275-c2cbf3f0-b5af-4662-a3fb-1fa21b4df91e.png)
###### 출처: git-scm (Git 브랜치)

위의 그림이 초기 히스토리라고 가정해보자.

![image](https://user-images.githubusercontent.com/61091307/148014483-06b87e5e-5866-4a95-9c21-d6508442d028.png)
###### 출처: git-scm (Git 브랜치)

이후 master 브랜치에서 iss53 브랜치와 hotfix 브랜치를 생성하고, 각각 하나의 commit을 하면 히스토리가 위의 그림처럼 된다.


![image](https://user-images.githubusercontent.com/61091307/148014672-c4988fa9-0858-4567-8471-2f5d48cb5de1.png)
###### 출처: git-scm (Git 브랜치)


1. hotfix 브랜치를 master 브랜치에 합치는 것은, 현재 브랜치 포인터가 merge할 브랜치의 조상을 가리키고 있으므로 별도의 commit 없이 **Fast Forward** merge가 가능하다. 

        (별도의 commit을 생성할 수는 있다.)
        git merge --no--ff hotfix

- hotfix 브랜치를 merge 했다면 해당 브랜치를 삭제한다.
    
        git branch -d hotfix

![image](https://user-images.githubusercontent.com/61091307/148014841-a2d0697f-416f-4df5-8b0a-49dcba1855bb.png)
###### 출처: git-scm (Git 브랜치)

2. iss53 브랜치를 master 브랜치에 합치는 것은, 현재 브랜치 포인터가 merge할 브랜치의 조상을 가리키고 있지 않으므로 commit을 생성하여 **3-way Merge** merge가 가능하다. 


## 2. Rebase

![image](https://user-images.githubusercontent.com/61091307/148017753-5572590a-5bee-4a82-bb79-6af9d45c6ad3.png)
###### 출처: git-scm (Git 브랜치)

앞에서 위의 상황이라면,

![image](https://user-images.githubusercontent.com/61091307/148017876-9c8a486d-be60-4774-a772-2d048188e232.png)
###### 출처: git-scm (Git 브랜치)

**3-way Merge**로 merge를 했었다.

![image](https://user-images.githubusercontent.com/61091307/148017876-9c8a486d-be60-4774-a772-2d048188e232.png)


이를 Rebase 방식으로도 합칠 수가 있다.
![image](https://user-images.githubusercontent.com/61091307/148018189-4a8493aa-097f-479a-8607-4b874d053d6b.png)
###### 출처: git-scm (Git 브랜치)

    git checkout experiment
    git rebase master

위의 명령어를 실행하게 되면, C2(두 브랜치가 나뉘기 전의 commit)로 이동한 후, 해당 commit부터 C4까지의 commit 사이의 diff를 만들어 C4'에 저장한다.

![image](https://user-images.githubusercontent.com/61091307/148018446-200c8c9e-f163-4497-aad9-40a54c214cb2.png)
###### 출처: git-scm (Git 브랜치)

    git checkout master
    git merge experiment

이후, 위의 명령어를 실행하면 **Fast Forward**로 merge할 수 있다.

- Merge와 Rebase는 최종적으로 결과는 같지만, commit history에서 차이가 있다.

- ***주의!** 협업을 하는 공개 저장소에 push한 commit을 Rebase하는 것은 위험하다.

- - -
## Reference
[Git SCM](https://git-scm.com/book/ko/v2)