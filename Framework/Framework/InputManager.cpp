#include "InputManager.h"

InputManager* InputManager::Instance = nullptr;


InputManager::InputManager() : Key(0) { }
InputManager::~InputManager() { }


void InputManager::InputKey()
{
	Key = 0;

	if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W'))
		Key |= KYE_UP;

	if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S'))
		Key |= KYE_DOWN;

	if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A'))
		Key |= KYE_LEFT;

	if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D'))
		Key |= KYE_RIGHT;

	if (GetAsyncKeyState(VK_SPACE))
		Key |= KYE_SPACE;

	if (GetAsyncKeyState(VK_RETURN))
		Key |= KYE_ENTER;

	if (GetAsyncKeyState(VK_CONTROL))
		Key |= KYE_CTRL;

	if (GetAsyncKeyState(VK_MENU))
		Key |= KYE_ALT;
     
}

/*
if (GetAsyncKeyState(VK_UP))
    cout << "KYE_UP" << endl;

if (GetAsyncKeyState(VK_DOWN))
    cout << "KYE_DOWN " << endl;

if (GetAsyncKeyState(VK_LEFT))
    cout << "KYE_LEFT " << endl;

if (GetAsyncKeyState(VK_RIGHT))
    cout << "KYE_RIGHT" << endl;

if (GetAsyncKeyState(VK_SPACE))
    cout << "KYE_SPACE" << endl;

if (GetAsyncKeyState(VK_RETURN))
    cout << "KYE_ENTER" << endl;

if (GetAsyncKeyState(VK_CONTROL))
    cout << "KYE_CTRL" << endl;

if (GetAsyncKeyState(VK_MENU))
    cout << "KYE_ALT" << endl;
 */