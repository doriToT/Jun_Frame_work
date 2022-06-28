#include "Stage.h"
#include "Player.h"
#include "SceneManager.h"
//#include "CursorManager.h"
#include "ObjectManager.h"

Stage::Stage() : pPlayer(nullptr) { }
Stage::~Stage() { Release(); }


void Stage::Initialize()
{
	list<Object*>* pPlayerList = ObjectManager::GetInstance()->GetObjectList("Player");

	if (pPlayerList != nullptr)
		pPlayer = pPlayerList->front();
}

void Stage::Update()
{
	ObjectManager::GetInstance()->Update();

	list<Object*>* pBulletList = ObjectManager::GetInstance()->GetObjectList("Bullet");


}

void Stage::Render()
{
	ObjectManager::GetInstance()->Render();
}

void Stage::Release()
{
	::Safe_Delete(pPlayer);
}
// p2p 연결방식은 모바일에서는 방이 터지거나 팅기면 다시 돌아갈 수가 없다.
// 모바일 게임에서는 프로그램(게임)이 종료가 되면 그 방에 대한 정보가 날라가기 때문에
