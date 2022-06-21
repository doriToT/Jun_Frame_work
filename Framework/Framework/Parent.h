#pragma once
#include "Headers.h"

#include <iostream>

using namespace std;

class Parent
{
private:
    //** 자기자신만 사용가능.

protected:
    //** 상속간의 공개된 상태, 비상속 클레스는 사용불가. 즉, 외부 사용불가
    int m_Number = 0;

public:
    //** 공개된 상태
    virtual void Initialize() = 0;
    virtual void Output() = 0;

    //virtual 은 자식 대신 해주는 것 
    // 
    // ** [virtual] = 가상함수
    // ** [ = 0] : virtual 함수에만 붙일 수 있다.
    // ** 함수의 끝에 [ = 0] 붙이게 되면 [순수 가상함수] 가 된다.
    
    // ** [순수 가상함수]
    // ** virtual 함수가 함수의 몸체(정의)가 없을 때 사용한다. 
    
    // ** virtual 함수를 사용하는 이유?
    // ** 순수 가상함수 사용이유 검색.  결정적으로 편리하게 하기 위해 (한번에 관리할 수 있으니)
};

