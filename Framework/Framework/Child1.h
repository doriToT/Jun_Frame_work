#pragma once
#include "Parent.h"

#include <iostream>

using namespace std;

class Child1 : public Parent
{
public:
private:
    //** �ڱ��ڽŸ� ��밡��.

protected:
    //** ��Ӱ��� ������ ����, ���� Ŭ������ ���Ұ�. ��, �ܺ� ���Ұ�
    int m_Number;

public:
    //** ������ ����
    void Initialize();
    void Update();
    void Output();

};

