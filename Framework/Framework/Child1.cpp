#include "Child1.h"

#include <iostream>

using namespace std;

void Child1::Initialize()
{
	m_Number = 100;
}

void Child1::Update()
{
	m_Number = 10;
}

void Child1::Output()
{
	cout << m_Number << endl;
}
