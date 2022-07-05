// ** Framework v6.2
#define CRT_SECURE_NO_WARNINGS
#include "Headers.h"
#include "MainUpdate.h"


using namespace std;


int main(void)
{

    system("title 홍길동 - Raiden");

    system("mode con cols=120 lines=30");

    MainUpdate Main;
    Main.Initialize();

    ULONGLONG Time = GetTickCount64(); // 1 / 1000

    while (true)
    {

        if (Time + 50 < GetTickCount64())
        {
            Time = GetTickCount64();

            system("cls");

            Main.Update();
            Main.Render();
        }
    }

    return 0;
}

// 두개의 버퍼(더블버퍼)를 사용하면 깜빡이는 현상을 유저가 볼 수 없다.
// 첫 번째가 업데이트된 후 두 번째가 나올때 미리 만들어진 것을 가져오고
// 첫 번째는 삭제되고 다시 불러올때 만들어서 다음 버퍼에 나오는 방식
// 정면에 띄우는 버퍼를 정면버퍼, 후면에 띄우는 버퍼를 후면버퍼라 한다.