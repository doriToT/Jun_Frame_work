#include "Bullet.h"
#include "CursorManager.h"

Bullet::Bullet() { }
Bullet::Bullet(Transform _TransInfo) : Object(_TransInfo) { }
Bullet::~Bullet() { }


void Bullet::Initialize()
{
	strKey = "Bullet";

	Buffer[0] = (char*)"��";
	Buffer[1] = (char*)"��";

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

	// Ÿ���� �߽��̸� Ÿ�� - ���� ��ġ


	Vector3 Target = Vector3(60.0f, 15.0f);

	/*
	//  <����>
	// Player���� ������ ��, Initialize ���Ŀ� SetPosition �����ϱ� ������
	// Direction������ Initialize�� ���ָ� Initialize�� ���� Position���� �ʱ� ��ġ�� ���� �Ź���.
	// 
	//  <���>
	// �Ʒ� ���� �� ���� ȣ���ص� �Ǳ� ������ �� ���� ����� �� �ִ� �Լ��� ����� �ݺ� ����� ���ؾ� ��.
	// ��¥�� �� ��ġ�� �ν��ϱ� ���� �Լ��� �ʿ��ϱ� ������, ��� �ϴ� �迡 �� �Լ��� ����� �ű⿡�� �ѹ��� ó���ϴ� �������.
	// 
	// ex) int b(bool�� ��ü)�� �� �Լ�(SetDirection)�� ����� Update���� ���ǽ����� ����� ����ϴ� ���
	// if (b == 0) SetDirection();
	// void SetDirection() { // ���� �ӵ� ������ ��� �ڵ� };
	*/

	// �̵� �ӵ� ������ ���
	Vector3 TargetVector = Target - TransInfo.Position; // �� �κ��� Initialize�� ������ �ȉ�
	float Distance = sqrt((TargetVector.x * TargetVector.x) + (TargetVector.y * TargetVector.y));

	// ������ ������ � ���⿡���� ��ǥ�� ���� (�뷫) ������ �ӵ��� �̵�.
	TransInfo.Direction.x = TargetVector.x / Distance;
	TransInfo.Direction.y = TargetVector.y / Distance;

	// ======

	// �̵� �� (���⿡ �ӵ� ���� ���ϱ�) : Update�� ���� ��
	TransInfo.Position += TransInfo.Direction;
	//TransInfo.Position += TransInfo.Direction * 2;

	// ======

	// �Ѿ��� ���� ��ġ
	//cout << "PosX : " << TransInfo.Position.x << endl;
	//cout << "PosY : " << TransInfo.Position.y << endl;

	// �Ѿ��� ���� �ӵ�
	//cout << "DirectionX : " << TransInfo.Direction.x << endl;
	//cout << "DirectionX : " << TransInfo.Direction.y << endl;

	// �Ѿ��� ���� �ӵ� 2
	float Average = sqrt(
		(TransInfo.Direction.x * TransInfo.Direction.x) +
		(TransInfo.Direction.y * TransInfo.Direction.y));
	// �˻�� : Target���� �Ÿ��� x1=3, y1=4, r1=5��� ������ ��, Direction�� ��ġ�� x2 == 3/5, y2 == 4/5�̴�.
	// �̸� ��Ÿ��� ���� ����ϸ� �̵����� r2 == ��((9/25) + (16/25)) == 1�� ���´�.
	// ��� : ���� �� ��� ���� 1�� ������ ������ �˻� �Ϸ�
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