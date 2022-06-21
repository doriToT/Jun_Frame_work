#pragma once

#include "Parent.h"

#include <iostream>

using namespace std;

class Bullet : public Parent
{
public:
private:
    //** 자기자신만 사용가능.

protected:
    //** 상속간의 공개된 상태, 비상속 클레스는 사용불가. 즉, 외부 사용불가
    int m_Number = 100;

public:
    //** 공개된 상태
    void Initialize();
    void Output();
};

