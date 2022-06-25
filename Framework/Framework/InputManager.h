#pragma once

#include "Headers.h"

class InputManager
{
private:
    static InputManager* Instance;
public:
    static InputManager* GetInstance()     // 싱글톤으로 만들었다. 대입연산자와 static이 있으면 const를 쓸 수 없다.
    {
        if (Instance == nullptr)
            Instance = new InputManager;    // << C에서는 가능하다 다른 곳에선 new Singleton() << 이게 기본형식

        return Instance;
    }

private:
    DWORD Key;
public:
    DWORD GetKey() const { return Key; }

public:
    void InputKey();
private:
    InputManager();
public:
    ~InputManager();
};

