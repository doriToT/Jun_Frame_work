#pragma once
#include "Object.h"

class Enemy : public Object
{
private:
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;

	virtual Object* Clone()override { return new Enemy(*this); }
public:
	Enemy();
	//Enemy(Transform _Info);  // �׽�Ʈ�Ҷ� �̰� ���ص���
	virtual ~Enemy();

};

