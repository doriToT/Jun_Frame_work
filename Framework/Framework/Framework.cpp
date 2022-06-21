// ** Framework v0.2
#include <iostream>
#include "Parent.h"
#include "Child1.h"
#include "Bullet.h"
#include "Headers.h"

using namespace std;


// 클래스(설명서) = 집합
// ** 1. 정보은닉
//      - 누구든지 수정할 수 있는 형태와 누구도 수정할 수 없는 형태 (정보가 은닉되어 있는 상태)
// ** private:   =    자기자신만 사용가능. 
// ** protected:  =   상속간의 공개된 상태, 비상속 클레스는 사용불가. 즉, 외부 사용불가
// ** public:    =    공개된 상태
// 
// ** 2. 캡슐화
//      - 데이터(변수)와 기능(함수)을 묶음으로 사용하는 것.
// 
// ** 3. 추상화
//      - 포괄적으로 공유된 것
//      - 추상 클래스는 객체화 시킬 수 없다.
//      - 존재하지 않는 형태를 추상 클래스라고 한다.
//      - 예) 사람, 학생, 군인 등의 대상이 특정되지 않는 경우(추상적인 경우)
//      - 반대 예) "홍길동은 학생이다." 라면 홍길동이라는 특정 대상이 있으므로,
//                  추상적인 형태로 볼 수 없다.
//      - 추상클래스 밑에 객체는 존재한다.
// 
// ** 4. 상속
//      - 위에서부터 받아들여지는 것 (자신이 들고있다는 유무는 필요 없다.)
//      
// 
// ** 5. 다형성
//      - 다양한 형태로 존재할 수 있다.
//      - 그러나 부모 클래스의 기존 형태가 바뀌지 않고 
//      - 자녀 클래스의 형태가 다양하게 존재할 수 있는 것이다.
// 
// ** 오브젝트(객체)
//    ex) 키보드를 구성하고있는 구성원들도 객체가 될 수 있고,
//        그 객체들이 모여서 또 다른 객체가 될 수도 있다. 즉, 모든 객체가 될 수 있다.
// 
//    - 추상화, 상속, 다형성이 어려운 부분이다. 각자 하나하나 이해하는 것 보단 다 같이 이해하는 것이 좋다.   
// 
//    - 객체들은 위 5가지 성질을 가지고 있다. 모든 객체는 무조건 클래스로 이루어져 있다.
//    - 허나 모든 클래스는 객체가 될 수 없다. (추상 클래스)

// ※ 접근방법은 점(.), 화살표(->), namespace(::) 이 3가지가 있다.


// ** 4. 상속
// 제일 이상적인 방법
/*
class AAA
{
protected:
    string m_str;

public:
    void Output()
    {
        cout << m_str << endl;
    }

};

class BBB : public AAA
{
private:

public:
    void Initialize() { m_str = "BBB"; }

};

class CCC : public AAA
{
private:

public:
    void Initialize() { m_str = "CCC"; }

};

      [main 출력]
       BBB b;
       b.Initialize();
       b.Output();
      
       CCC c;
       c.Initialize();
       c.Output();

*/

// ** 5. 다형성

// ** 6. namespace
// 동일한 이름을 다른영역으로 만들어 그 함수에 대한 구분이 가능하게 해준다.
// 해당하는 함수만 별도로 설정가능하고 그 함수를 통째로 설정가능하다.
//** 별도의 영역을 지정하여 동일한 이름의 함수(변수를 사용하는 것도 가능하다)를 사용할 수 있도록 함.

// ** 7. 생성자 & 소멸자 & 복사 생성자
// 
// ** 8. 깊은복사 얕은 복사
// 
// ** 9. 오버로딩 & 오버라이딩
// 

// ** 10. 연산자 오버로딩
//

// ** 11. 포인터





// 런타임 이후에는 스택이랑 힙이 올라간다.
// 런타임 전에는 static, 코드 등등

/*
namespace AAA
{
    void Output()
    {
        cout << "홍길동" << endl;
    }
}

using namespace AAA;
using AAA::Output;

namespace BBB
{
    void Output()
    {
        cout << "임꺽정" << endl;
    }
}
*/

const int ID_Child = 0;
const int ID_Bullet = 1;

int main(void)
{
    Parent* p[2];

    p[ID_Child] = new Child1;
    p[ID_Bullet] = new Bullet;

    for (int i = 0; i < 2; ++i)
    {
        p[i]->Initialize();
        p[i]->Output();
    }

   

    /*
    Child1 c;

    c.Initialize();
    c.Output();

    Bullet b;

    b.Initialize();
    b.Output();
    */

    

 
    


    return 0;
}