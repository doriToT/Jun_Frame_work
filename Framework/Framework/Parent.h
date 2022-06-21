#pragma once
#include "Headers.h"

#include <iostream>

using namespace std;

class Parent
{
private:
    //** �ڱ��ڽŸ� ��밡��.

protected:
    //** ��Ӱ��� ������ ����, ���� Ŭ������ ���Ұ�. ��, �ܺ� ���Ұ�
    int m_Number = 0;

public:
    //** ������ ����
    virtual void Initialize() = 0;
    virtual void Output() = 0;

    //virtual �� �ڽ� ��� ���ִ� �� 
    // 
    // ** [virtual] = �����Լ�
    // ** [ = 0] : virtual �Լ����� ���� �� �ִ�.
    // ** �Լ��� ���� [ = 0] ���̰� �Ǹ� [���� �����Լ�] �� �ȴ�.
    
    // ** [���� �����Լ�]
    // ** virtual �Լ��� �Լ��� ��ü(����)�� ���� �� ����Ѵ�. 
    
    // ** virtual �Լ��� ����ϴ� ����?
    // ** ���� �����Լ� ������� �˻�.  ���������� ���ϰ� �ϱ� ���� (�ѹ��� ������ �� ������)
};

