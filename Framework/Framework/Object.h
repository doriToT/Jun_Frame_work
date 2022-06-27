#pragma once
#include "Headers.h"

class Object
{
protected:
	string strKey;
public:
	virtual void Initialize()PURE;
	virtual void Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
	virtual Object* Clone()PURE; // �׽�Ʈ�Ҷ� �̰� ���ص���
public:
	string GetKey() const { return strKey; }

public:
	Object();
	//Object(Transform _Info); // �׽�Ʈ�Ҷ� �̰� ���ص���
	virtual ~Object();
};

