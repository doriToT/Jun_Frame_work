#pragma once
#include "Headers.h"


class Object;
class prototype
{
private:
	static prototype* Instance;
public:
	static prototype* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new prototype;
		return Instance;
	}
private:
	map<string, Object*> ProtoTypeList;
public:
	void Initialize();
	Object* ProtoTypeObject(string _Key);
private:
	prototype();
public:
	~prototype();
};

