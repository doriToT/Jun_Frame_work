#pragma once

#include "Headers.h"
#include "MainUpdate.h"

class InputManager
{
private:
    static InputManager* Instance;
public:
    static InputManager* GetInstance()
    {
        if (Instance == nullptr)
            Instance = new InputManager;    // << C에서는 가능하다 다른 곳에선 new Singleton() << 이게 기본형식

        return Instance;
    }

private:
    DWORD Key;
public:
    void InputKey();
private:
    InputManager();
public:
    ~InputManager();
};

