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
	virtual Object* Clone()PURE; // 테스트할때 이거 안해도됨
public:
	string GetKey() const { return strKey; }

public:
	Object();
	//Object(Transform _Info); // 테스트할때 이거 안해도됨
	virtual ~Object();
};

