#include "Object.h"

Object::Object() : pBridge(nullptr) { }
Object::Object(Transform _TransInfo) : TransInfo(_TransInfo) { }
Object::~Object() { }


// 앞선 private 에 있는 것들은 초기화 해줘야한다. 정석