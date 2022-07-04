#include "Bullet.h"
#include "CursorManager.h"

Bullet::Bullet() { }
Bullet::Bullet(Transform _TransInfo) : Object(_TransInfo) { }
Bullet::~Bullet() { }


void Bullet::Initialize()
{
	strKey = "Bullet";

	Buffer[0] = (char*)"＼";
	Buffer[1] = (char*)"／";

	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(2.0f, 2.0f);
	//TransInfo.Direction = Vector3(0.1f, -0.06f);


	Vector3 Target = Vector3(60.0f, 15.0f);

	Vector3 Result = Target - TransInfo.Position;


	float Distance = sqrt((Result.x * Result.x) + (Result.y * Result.y));

	TransInfo.Direction /= Distance;
}

int Bullet::Update()
{

	// 타겟이 중심이면 타겟 - 나의 위치


	Vector3 Target = Vector3(60.0f, 15.0f);

	/*
	//  <원인>
	// Player에서 생성할 때, Initialize 이후에 SetPosition 적용하기 때문에
	// Direction계산법을 Initialize에 써주면 Initialize에 적힌 Position으로 초기 위치가 설정 돼버림.
	// 
	//  <대안>
	// 아래 식은 한 번만 호출해도 되기 때문에 한 번만 실행될 수 있는 함수를 만들어 반복 계산을 피해야 함.
	// 어짜피 적 위치를 인식하기 위한 함수가 필요하기 때문에, 기왕 하는 김에 새 함수를 만들어 거기에서 한번에 처리하는 방식으로.
	// 
	// ex) int b(bool값 대체)와 새 함수(SetDirection)를 사용해 Update에서 조건식으로 만들어 사용하는 방법
	// if (b == 0) SetDirection();
	// void SetDirection() { // 이하 속도 증가량 계산 코드 };
	*/

	// 이동 속도 증가량 계산
	Vector3 TargetVector = Target - TransInfo.Position; // 이 부분이 Initialize에 있으면 안됌
	float Distance = sqrt((TargetVector.x * TargetVector.x) + (TargetVector.y * TargetVector.y));

	// 이하의 식으로 어떤 방향에서든 목표에 대해 (대략) 동일한 속도로 이동.
	TransInfo.Direction.x = TargetVector.x / Distance;
	TransInfo.Direction.y = TargetVector.y / Distance;

	// ======

	// 이동 식 (여기에 속도 값을 곱하기) : Update에 있을 것
	TransInfo.Position += TransInfo.Direction;
	//TransInfo.Position += TransInfo.Direction * 2;

	// ======

	// 총알의 현재 위치
	//cout << "PosX : " << TransInfo.Position.x << endl;
	//cout << "PosY : " << TransInfo.Position.y << endl;

	// 총알의 현재 속도
	//cout << "DirectionX : " << TransInfo.Direction.x << endl;
	//cout << "DirectionX : " << TransInfo.Direction.y << endl;

	// 총알의 현재 속도 2
	float Average = sqrt(
		(TransInfo.Direction.x * TransInfo.Direction.x) +
		(TransInfo.Direction.y * TransInfo.Direction.y));
	// 검산식 : Target까지 거리를 x1=3, y1=4, r1=5라고 가정할 때, Direction의 수치는 x2 == 3/5, y2 == 4/5이다.
	// 이를 피타고라스 식을 사용하면 이동량은 r2 == √((9/25) + (16/25)) == 1이 나온다.
	// 결론 : 실행 시 출력 값이 1이 나오는 것으로 검산 완료
	//cout << "Speed : " << Average << endl << endl;


	/*
	TransInfo.Position.x += 2.0f;
	*/
	
	return 0;
}

void Bullet::Render()
{
	for (int i = 0; i < MAX_SIZE; ++i)
	{
		CursorManager::Draw(
			TransInfo.Position.x - (TransInfo.Scale.x * 0.5f),
			TransInfo.Position.y - (TransInfo.Scale.x * 0.5f) + i,
			Buffer[i]);
	}
}

void Bullet::Release()
{

}