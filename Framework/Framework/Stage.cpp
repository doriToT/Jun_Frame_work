#include "Stage.h"
#include "Player.h"
#include "SceneManager.h"
#include "InputManager.h"

#include "ObjectManager.h"


Stage::Stage() : pPlayer(nullptr){ }
Stage::~Stage() { Release(); }


void Stage::Initialize()
{
	// ** 1. 변형 형태가  list<Object*>
	// ** 2. Key가 전달이 되어야 한다.
	//pPlayer = new Player;
	//pPlayer->Initialize();
	//pPlayer = ObjectManager::GetInstance()->
	//pPlayer = ObjectManager::GetInstance()->GetObjectList("Player")->front();
	list<Object*>* pPlayerList = ObjectManager::GetInstance()->GetObjectList("Player"); 

	if (pPlayerList != nullptr)
		pPlayer = pPlayerList->front();//->Clone(); // 테스트할때 이거 안해도됨 클론빼고
}



void Stage::Update()
{
	if(pPlayer)
	   pPlayer->Update();
}

void Stage::Render()
{
	//pPlayer->Render();
	if (pPlayer)
		pPlayer->Render();

	ObjectManager::GetInstance()->Render();
}

void Stage::Release()
{
	::Safe_Delete(pPlayer);
}

// p2p 연결방식은 모바일에서는 방이 터지거나 팅기면 다시 돌아갈 수가 없다.
// 모바일 게임에서는 프로그램(게임)이 종료가 되면 그 방에 대한 정보가 날라가기 때문에
