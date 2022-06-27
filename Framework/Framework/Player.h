#pragma once
#include "Object.h"

class Player : public Object
{
private:
	int Horizontal;
	int Vertical;
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
	
    virtual Object* Clone()override { return new Player(*this); } // 테스트할때 이거 안해도됨
public:
	Player();
	//Player(Transform _Info); // 테스트할때 이거 안해도됨
	virtual ~Player();
};

