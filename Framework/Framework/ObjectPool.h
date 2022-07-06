#pragma once
#include "Headers.h"

class Object;
class ObjectPool
{
private:
	static ObjectPool* Instance;
public:
	static ObjectPool* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new ObjectPool;
		return Instance;
	}
private:
	// 현재 돌아가고 눈에 보이는 곳에서만 쓰겠다. static은 staic으로 불러올 수 밖에 없다.
	static map<string, list<Object*>> EnableList;
	map<string, list<Object*>> DisableList;
public:
	static map<string, list<Object*>>* GetEnableList() { return &EnableList; }
	void Update();
private:
	ObjectPool();
public:
	~ObjectPool();
};
