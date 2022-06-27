#include "Enemy.h"

Enemy::Enemy() { }

//Enemy::Enemy(Transform _Info) : Object(_Info) { }  // 테스트할때 이거 안해도됨

Enemy::~Enemy() { }


void Enemy::Initialize()
{
	strKey = "Enemy";
}

void Enemy::Update()
{
}

void Enemy::Render()
{
	Message("Enemy");
}

void Enemy::Release()
{
}

