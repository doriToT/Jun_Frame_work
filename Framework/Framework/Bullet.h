#pragma once

#include "Parent.h"

#include <iostream>

using namespace std;

class Bullet : public Parent
{
public:
private:
    //** �ڱ��ڽŸ� ��밡��.

protected:
    //** ��Ӱ��� ������ ����, ���� Ŭ������ ���Ұ�. ��, �ܺ� ���Ұ�
    int m_Number = 100;

public:
    //** ������ ����
    void Initialize();
    void Output();
};

