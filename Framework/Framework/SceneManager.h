#pragma once

#include "Headers.h"

class SceneManager
{
private:
    static SceneManager* Instance;
public:
    static SceneManager* GetInstance()
    {
        if (Instance == nullptr)
            Instance = new SceneManager;    // << C에서는 가능하다 다른 곳에선 new Singleton() << 이게 기본형식

        return Instance;
    }

private:

public:
    void SetScene(int _SceneState);
private:
    SceneManager();
public:
    ~SceneManager();
};

