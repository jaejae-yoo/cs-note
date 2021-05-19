## 1. Wrapper 클래스

기본 타입(primitive type)을 객체로 다루기 위해 만든 클래스를 Wrapper 클래스라 한다.

       boxing
    byte ➔ Byte 
    short ➔ Short
    int ➔ Integer
    long ➔ Long
    char ➔ Character
    float ➔ Float
    double ➔ Double
    boolean ➔ Boolean



## 2. 컬렉션(Collection) 

컬렉션은 제네릭(generics)이라는 기법으로 구현되어 있다.

###### <대표적인 컬렉션 인터페이스와 클래스>
![image](https://user-images.githubusercontent.com/61091307/118845321-a68af900-b906-11eb-9195-db4a37efabfd.png)


컬렉션 클래스를 선언할 때는 <E>, <K>, <V> 등이 포함되어 있는데 이를 '타입 매개 변수'라고 하며 제네릭 타입(generic type)이라 부른다. 컬렉션은 여러 타입으로 변경이 가능한 자료구조 이지만,  타입을 지정해주게 되면 지정된 타입의 값만 저장할 수 있다.

또한 컬렉션의 요소는 객체들만 가능하므로 기본 타입(Primitive Type)은 Reference Type(참조형)으로 변환해야 한다. (기본 타입이 삽입되면 Wrapper 클래스 타입으로 auto boxing 된다.)

### 제네릭(generics)
제네릭은 모든 종류의 타입을 사용할 수 있도록 클래스나 메소드를 타입 매개변수(generic type)을 이용하여 선언하는 기법이다. 



## 3. 인터페이스 (interface)

인터페이스는 스펙을 주어 클래스들이 그 기능을 서로 다르게 구현할 수 있도록 하는 클래스의 규격 선언이며 클래스의 '다형성(Polymorphism)'을 실현하는 도구이다. 

- 인터페이스는 객체를 생성할 수 없다.
- 인터페이스 타입의 레퍼런스 변수는 선언 가능하다.
- 인터페이스를 상속받아 클래스를 작성하면 인터페이스의 모든 추상 메소드를 구현해야 한다.
- 인터페이스끼리 상속된다.

## Reference
명품 JAVA Programming, 4th Ed, 황기태