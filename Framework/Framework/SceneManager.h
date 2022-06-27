#pragma once

#include "Headers.h"

class Scene;     // 클레스를 정의없이 만든것 가상의 클레스
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
    Scene* SceneState;      // 있는 척만 할거다.
public:
    void SetScene(SCENEID _SceneState);
    void Update();
    void Render();
    void Release();
private:
    SceneManager();
public:
    ~SceneManager();
};

