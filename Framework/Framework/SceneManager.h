#pragma once

#include "Headers.h"

class Scene;     // Ŭ������ ���Ǿ��� ����� ������ Ŭ����
class SceneManager
{
private:
    static SceneManager* Instance;
public:
    static SceneManager* GetInstance()
    {
        if (Instance == nullptr)
            Instance = new SceneManager;    // << C������ �����ϴ� �ٸ� ������ new Singleton() << �̰� �⺻����

        return Instance;
    }

private:
    Scene* SceneState;      // �ִ� ô�� �ҰŴ�.
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

