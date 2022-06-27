#include "ObjectManager.h"
#include "Object.h"

ObjectManager* ObjectManager::Instance = nullptr;

ObjectManager::ObjectManager() { }

ObjectManager::~ObjectManager() { }

void ObjectManager::AddObject(Object* _Object)
{
	map<string, list<Object*>>::iterator iter = ObjectList.find(_Object->GetKey());

	if (iter == ObjectList.end())
	{
		list<Object*> TempList;
		TempList.push_back(_Object);
		ObjectList.insert(make_pair(_Object->GetKey(), TempList));
	}
	else
		iter->second.push_back(_Object);
}

list<Object*>* ObjectManager::GetObjectList(string _strKey)
{
	map<string, list<Object*>>::iterator iter = ObjectList.find(_strKey);

	if (iter == ObjectList.end())
		return nullptr;

	list<Object*> Temp;

	return &iter->second;
}


void ObjectManager::Render() // 이거는 작성 안해도 됨.
{
	for (map<string, list<Object*>>::iterator iter = ObjectList.begin();
		iter != ObjectList.end(); ++iter)
		for (list<Object*>::iterator iter2 = iter->second.begin();
			iter2 != iter->second.end(); ++iter2)
			(*iter2)->Render();
}
