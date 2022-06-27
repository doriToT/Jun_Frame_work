#include "Stage.h"
#include "Player.h"
#include "SceneManager.h"
#include "InputManager.h"

#include "ObjectManager.h"


Stage::Stage() : pPlayer(nullptr){ }
Stage::~Stage() { Release(); }


void Stage::Initialize()
{
	// ** 1. ���� ���°�  list<Object*>
	// ** 2. Key�� ������ �Ǿ�� �Ѵ�.
	//pPlayer = new Player;
	//pPlayer->Initialize();
	//pPlayer = ObjectManager::GetInstance()->
	//pPlayer = ObjectManager::GetInstance()->GetObjectList("Player")->front();
	list<Object*>* pPlayerList = ObjectManager::GetInstance()->GetObjectList("Player"); 

	if (pPlayerList != nullptr)
		pPlayer = pPlayerList->front();//->Clone(); // �׽�Ʈ�Ҷ� �̰� ���ص��� Ŭ�л���
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

// p2p �������� ����Ͽ����� ���� �����ų� �ñ�� �ٽ� ���ư� ���� ����.
// ����� ���ӿ����� ���α׷�(����)�� ���ᰡ �Ǹ� �� �濡 ���� ������ ���󰡱� ������
