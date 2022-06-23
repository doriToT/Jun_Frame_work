// ** Framework v1.0
#define CRT_SECURE_NO_WARNINGS

#include "Headers.h"
#include "MainUpdate.h"

#include <Windows.h>

#include <iostream>
#include <vector>
#include <list>
#include <map>


using namespace std;

// API를 안쓰려고 쓰는게 MFC이다.
// 윈도우 대부분의 기능은 API로 만드는게 많다.
//

//** 루프는 실행되는 순서가 정해져 있다.
//** GetTickCount   대략 49일
//** GetTickCount64 대략 5억년

//** Singleton
// 관리자로 쓸 것 하나만 만들어야한다. 외부에서 만들 수 없는 상태여야한다.
// 생성자를 private에 둔다.
// 데이터를 언제든지 어디서나 쓸 수 있게 만드는
// 실생활에서는 서버실이다

/*
class Singleton
{
private:
    static Singleton* Instance;
public:
    static Singleton* GetInstance()
    {
        if (Instance == nullptr)
            Instance = new Singleton;    // new Singleton() << 이게 기본형식

        return Instance;
    }

private:
    int Number;
public:
    int GetNumber() const { return Number; }
    void SetNumber(const int& _Number) { Number = _Number; }

private:
    Singleton() : Number(0) {}
public:
    ~Singleton() {}
};


Singleton* Singleton::Instance = nullptr;
*/


int main(void)
{
    /*
    Singleton::GetInstance()->SetNumber(10);
    cout << Singleton::GetInstance()->GetNumber() << endl;
    */

    /*
    MainUpdate Main;
    Main.Initialize();

    ULONGLONG Time = GetTickCount64();  // 1 / 1000 프로그램을 무한정 켜둘 순 없다.


    while (true)
    {
        if (Time + 50 < GetTickCount64())
        {
            Time = GetTickCount64();

            system("cls");  // 버퍼 지우는 기능

            
            Main.Update();
            Main.Render();


        }
    }
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