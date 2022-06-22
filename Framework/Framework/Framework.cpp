// ** Framework v0.2
#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Parent.h"
#include "Child1.h"
#include "Bullet.h"
#include "Headers.h"

#include <vector>
#include <map>

using namespace std;


// 클래스(설명서) = 집합


// ** 7. 생성자 & 소멸자 & 복사 생성자
// ** 8. 깊은복사 얕은 복사
// ** (복사생성자)

/*
struct tagInfo
{
    int Number;
};


tagInfo Info;

class Object
{
protected:
    tagInfo m_Info;
public:
    int Number;
    char* Name;

public:
    virtual Object* Clone() = 0;


public:
    
    
    //** 사용자가 호출하지 않아도 스스로 호출됨.
    //** 클래스가 생성된 직후 호출
    Object()   // 생성자
    {
        cout << "생성자" << endl;
    };    
    
    //** 사용자가 호출하는 시점에 호출됨.
    //** 클래스가 생성되거나 삭제되는 것이 아닌 언제든지 호출가능하다.
    //** 전달값의 개수와 자료형(int인지 float인지)에 따라서 선택적(자동)으로 호출 됨.
    Object(int _Number) : Number(_Number)  // 생성자
    {
        cout << "복사 생성자: int" << endl;

       // Number = _Number;
    };

    Object(float _Number)   // 생성자
    {
        cout << "복사 생성자: float" << endl;

        Number = (int)_Number;
        
    };

    Object(char* _Name)   // 생성자
    {
        Name = new char[strlen(_Name) + 1];
        strcpy(Name, _Name);
    };

    Object(Object* _Obj)
    {
        Name = new char[strlen(_Obj->Name) + 1];
        strcpy(Name, _Obj->Name);
    }

    
    Object(Object* _Obj)   // 생성자
    {
        //Number = _Obj->Number;  // 주소만 복사하기 때문에 동적할당을 해야한다.

        //Name = new char(strlen(_Obj->Name) + 1);  // 동적할당
        //strcpy(Name, _Obj->Name);
    };
    

    Object(tagInfo _Info) : m_Info(_Info)
    {

    }

    //** 클래스가 삭제되기 직전
    ~Object()  // 소멸자
    {
        cout << "소멸자" << endl;

        //delete[] Name;
        //Name = nullptr;
    };
};



class Player : public Object
{
public:

    virtual Object* Clone() override
    {
        return new Player(*this);
    }


    void Output() { cout << m_Info.Number << endl; }

    Player() {};
    Player(tagInfo _Info) : Object(_Info) { };
    ~Player() {};
};
*/

// 네임스페이스 -> '점 4개로 이루어져있다' 이렇게 외운다.
// ** 9. 오버로딩 & 오버라이딩   -> 같은 함수 이름을 똑같이 쓸 수 있다 (네임스페이스 도 가능)
//     1) 오버로딩 (=복사 생성자와 거의 같다)
//       - 전달값의 개수와 자료형(int인지 float인지)에 따라서 선택적(자동)으로 호출 됨. 
//       - 매개변수의 개수와 형태가 달라야한다. (같은 이름의 함수를 쓰려면)
//       - 자기 함수 내의 영역에 쓸 수 있다.
//     2) 오버라이딩
//       - 상속의 범위가 크다 (무조건 상속이 되어있다.)
//       - 함수이름과 매개변수의 개수와 형태까지 일치되어야 한다. (부모한테도 있고 자식에도 있는)
//       - 오버로딩된 애가 오버라이딩이 될 수 있다. 즉, 둘다(오버로딩과 오버라이딩) 쓸 수 있다.
//
//     오버로딩과 오버라이딩의 핵심은 어떻게 출력할 것이냐 이다.

/*
class Object
{
public:
    virtual void Output()        // 오버 로딩
    {
        cout << "" << endl;

    }
    virtual void Output(string _str)  // 오버로딩
    {
        cout << _str << endl;
    }
};

class AAA : public Object   // 오버 라이딩
{
public:
    void Output() override
    {
        cout << "AAA : " << endl;

    }
    void Output(string _str) override
    {
        cout << "AAA : " << _str << endl;
    }
};
*/


// ** 10. 연산자 오버로딩
//

/*
struct tagInfo
{
    int Number;

    tagInfo() {};
    tagInfo(int _Number) : Number(_Number) {};
};

class Object
{
private:
    tagInfo Info;
public:
    //** 
    Object& operator+=(const Object& _Obj)
    {
        Info.Number += _Obj.Info.Number;
        return *this;
    }

    Object& operator++()
    {
        Info.Number += 1;
        return *this;
    }
    
    void Output()
    {
        cout << Info.Number << endl;
    }

public:
    Object() { }
    Object(tagInfo _Info) : Info(_Info) { }
    ~Object() { }

};
*/

// ** 11. 포인터(복습) & 캡슐화




// 런타임 이후에는 스택이랑 힙이 올라간다.
// 런타임 전에는 static, 코드 등등

//map<string, Object*> PortotypeObject;

//Object* GetObject(string _Key);

int main(void)
{
    /*
    Object o = Object(3.141592f);     // 복사 생성자 호출

    cout << "Hello World!" << endl;
    

    //Object o = Object(Object()); // 기본적으로 제공

    Object o1;
    o1.Number = 10;

    o1.Name = (char*)"홍길동";
    Object o2(o1);
    */

    /*
    tagInfo Info;

    AAA a[8];

    for (int i = 0; i < 8; ++i)
    {
        Info.Number = i + 1;
        a[i] = AAA(Info);
    }

    for (int i = 0; i < 8; ++i)
        a[i].Output();
    */

    /*
     예제
    
    tagInfo Info;

    Info.Number = 10;
    PortotypeObject["Player"] = new Player(Info);

    Object* pProtoObj = GetObject("Player");

    Object* pPlayer = nullptr;

    if (pProtoObj != nullptr)
        pPlayer = pProtoObj->Clone();
    */


    /*
    Object o1(tagInfo(10));
    Object o2(o1);

    o2 += o1;

    ++o2;

    o2.Output();
    */

    return 0;
}

/*
Object* GetObject(string _Key)
{
    map<string, Object*>::iterator iter = PortotypeObject.find(_Key);

    if (iter == PortotypeObject.end())
        return nullptr;
    else


    return nullptr;
}
*/