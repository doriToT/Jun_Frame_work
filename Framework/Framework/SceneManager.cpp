#include "SceneManager.h"

#include "Logo.h"
#include "Menu.h"
#include "Stage.h"

// 변수가 선언되어 있으면 초기화를 무조건 시켜줘야 한다.
SceneManager* SceneManager::Instance = nullptr;

SceneManager::SceneManager() : SceneState(nullptr) {}
SceneManager::~SceneManager() { Release(); }


void SceneManager::SetScene(SCENEID _SceneState)
{
	if (SceneState != nullptr)
	{
		::Safe_Delete(SceneState);   // 앞에 아무것도 없고 :: 나온다면 inline 함수이다.
	}

	switch (_SceneState)
	{
	case SCENEID::LOGO:
		SceneState = new Logo;
		break;

	case SCENEID::MENU:
		SceneState = new Menu;
		break;

	case SCENEID::STAGE:
		SceneState = new Stage;
		break;

	case SCENEID::EXIT:
		exit(NULL);
		break;
	}
	SceneState->Initialize();

}

void SceneManager::Update()
{
	SceneState->Update();
}

void SceneManager::Render()
{
	SceneState->Render();
}

void SceneManager::Release()
{
	::Safe_Delete(SceneState);
}
