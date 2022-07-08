#include "prototype.h"

#include "Player.h"
#include "Bullet.h"
#include "Object.h"
#include "Enemy.h"
#include "ObjectManager.h"


prototype* prototype::Instance = nullptr;

prototype::prototype()
{
}

prototype::~prototype()
{
}

void prototype::Initialize()
{
	Transform Info;

	string Key = "Player";
	ProtoTypeList[Key] = (new Player(Info))->Initialize(Key);

	Key = "Enemy";
	ProtoTypeList[Key] = (new Enemy(Info))->Initialize(Key);

	Key = "Bullet";
	ProtoTypeList[Key] = (new Bullet(Info))->Initialize(Key);

}

Object* prototype::ProtoTypeObject(string _Key)
{
	map<string, Object*>::iterator iter = ProtoTypeList.find(_Key);
	
	if (iter == ProtoTypeList.end())
		return nullptr;

	return iter->second;
}
