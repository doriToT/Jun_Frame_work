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
            Instance = new InputManager;    // << C������ �����ϴ� �ٸ� ������ new Singleton() << �̰� �⺻����

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

