#include "Stage.h"
#include "Player.h"
#include "Enemy.h"
#include "ScrollBox.h"
#include "SceneManager.h"
#include "CollisionManager.h"
#include "InputManager.h"
#include "CursorManager.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"

Stage::Stage() : Check(0) { }
Stage::~Stage() { Release(); }


void Stage::Initialize()
{
	Check = 0;

	Object* pEnemyProto = ObjectFactory<Enemy>::CreateObject();

	pUI = new ScrollBox;
	pUI->Initialize();

	for (int i = 0; i < 5; ++i)
	{
		srand(DWORD(GetTickCount64() * (i + 1)));

		Object* pEnemy = pEnemyProto->Clone();
		//pEnemy->SetPosition(118.0f, float(rand() % 30));
		pEnemy->SetPosition(float(rand() % 118), float(rand() % 30));

		ObjectManager::GetInstance()->AddObject(pEnemy);
	}
}

void Stage::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_TAB)
	{
		Enable_UI();
	}

	ObjectManager::GetInstance()->Update();

	Object* pPlayer = ObjectManager::GetInstance()->GetObjectList("Player")->front();
	list<Object*>* pBulletList = ObjectManager::GetInstance()->GetObjectList("Bullet");
	list<Object*>* pEnemyList = ObjectManager::GetInstance()->GetObjectList("Enemy");

	if (pBulletList != nullptr)
	{
		for (list<Object*>::iterator iter = pBulletList->begin();
			iter != pBulletList->end(); )
		{
			if ((*iter)->GetPosition().x >= 120.0f)
				iter = pBulletList->erase(iter);
			else
				++iter;
		}
	}

	if (pPlayer != nullptr)
	{
		if (pEnemyList != nullptr)
		{
			for (list<Object*>::iterator Enemyiter = pEnemyList->begin();
				Enemyiter != pEnemyList->end(); ++Enemyiter)
			{
				if (CollisionManager::Collision(pPlayer, *Enemyiter))
				{




				}

				if (pBulletList != nullptr)
				{
					for (list<Object*>::iterator Bulletiter = pBulletList->begin();
						Bulletiter != pBulletList->end(); ++Bulletiter)
					{
						if (CollisionManager::Collision(*Bulletiter, *Enemyiter))
						{




						}
					}
				}
			}
		}
	}

	if (Check)
		pUI->Update();
}

void Stage::Render()
{
	ObjectManager::GetInstance()->Render();

	if (Check)
		pUI->Render();
}

void Stage::Release()
{

}

void Stage::Enable_UI()
{
	Check = !Check;
}

// p2p 연결방식은 모바일에서는 방이 터지거나 팅기면 다시 돌아갈 수가 없다.
// 모바일 게임에서는 프로그램(게임)이 종료가 되면 그 방에 대한 정보가 날라가기 때문에
