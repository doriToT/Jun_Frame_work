#pragma once
#include "Headers.h"

class Object;
class ObjectManager
{
private:
    static ObjectManager* Instance;   // << 싱글톤이다.
public:
    static ObjectManager* GetInstance()   // << 싱글톤이다.
    {
        if (Instance == nullptr)
            Instance = new ObjectManager;    // << C에서는 가능하다 다른 곳에선 new Singleton() << 이게 기본형식

        return Instance;
    }

private:
    map<string, list<Object*>> ObjectList;

public:
    void AddObject(Object* _Object);
    // ** 1. 반환 형태가 list<Object*>  
    // ** 2. Key가 전달되어야 함.

    list<Object*>* GetObjectList(string _strKey);

    void Render();
private:
    ObjectManager();
public:
    ~ObjectManager();
};

