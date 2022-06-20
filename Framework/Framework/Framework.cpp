#include <iostream>

using namespace std;

// 클래스(설명서) = 집합
// ** 1. 정보은닉
//      - 누구든지 수정할 수 있는 형태와 누구도 수정할 수 없는 형태 (정보가 은닉되어 있는 상태)
// ** 2. 캡슐화
//      - 함수와 데이터가 따로 되어있는 형태. 자신의 기능은 자신만 쓸 수 있다.
//      - 각각의 기능을 따로 정해져 있는 것
// ** 3. 추상화
//      - 포괄적으로 공유된 것이 있다
// ** 4. 상속
//      - 위에서부터 받아들여지는 것 (자신이 들고있다는 유무는 필요 없다.)
// ** 5. 다형성
//      - 형태가 다를 수 있다. (얼마든지 다를 수 있다,)
// ** 오브젝트(객체)
//    ex) 키보드를 구성하고있는 구성원들도 객체가 될 수 있고,
//        그 객체들이 모여서 또 다른 객체가 될 수도 있다. 즉, 모든 객체가 될 수 있다.
// 
//    - 객체들은 위 5가지 성질을 가지고 있다. 모든 객체는 무조건 클래스로 이루어져 있다.
//    - 허나 모든 클래스는 객체가 될 수 없다. (추상 클래스)




// 구조체는 기본적으로 public이다.
struct AAA
{
//private:         // C에서는 안된다.
    int Number = 0;
};


// 클래스는 다르다.
class BBB            // m_  << 가 있으면 그 클래스의 멤버이다.
{
private:
    int m_iNumber;
    
public:            // public은 신중하게 써야한다.

    void Initialize()
    {
        m_iNumber = 10;
    }

    //** 데이터를 사용하는 것은 가능하지만 수정은 불가. (get은 받는 것이 가능)
    int GetNumber()
    {
        return m_iNumber;
    }
    //** 데이터를 수정하는 것은 가능하지만 참조는 불가. (set은 보내는 것이 가능)
    void SetNumber(int _Number) 
    {
        m_iNumber = _Number; 
    }
    // get & set은 모듈화가 좋다.
};

class CCC            // m_  << 가 있으면 그 클래스의 멤버이다.
{
private:
    int m_iNumber;

public:            // public은 신중하게 써야한다.

    void Initialize()
    {
        m_iNumber = 100;
    }

    //** 데이터를 사용하는 것은 가능하지만 수정은 불가. (get은 받는 것이 가능)
    int GetNumber()
    {
        return m_iNumber;
    }
    //** 데이터를 수정하는 것은 가능하지만 참조는 불가. (set은 보내는 것이 가능)
    void SetNumber(int _Number)
    {
        m_iNumber = _Number;
    }
    // get & set은 모듈화가 좋다.
};

void Initialize(int& _Number)
{

}



int main(void)
{
    AAA a;
    Initialize(a.Number);
    cout << a.Number << endl;

    BBB b;
    //b.Number;    바로 사용할 수 없음. Private 이기 때문
    b.Initialize();
    //b.SetNumber(10);
    cout << b.GetNumber() << endl;

    CCC c;
    c.Initialize();
    cout << c.GetNumber() << endl;
   

    return 0;
}