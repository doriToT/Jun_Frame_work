#pragma once

#include "Headers.h"

class InputManager
{
private:
    static InputManager* Instance;
public:
    static InputManager* GetInstance()     // �̱������� �������. ���Կ����ڿ� static�� ������ const�� �� �� ����.
    {
        if (Instance == nullptr)
            Instance = new InputManager;    // << C������ �����ϴ� �ٸ� ������ new Singleton() << �̰� �⺻����

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

