// ** Framework v2.3
#define CRT_SECURE_NO_WARNINGS

#include "Headers.h"
#include "Constant.h"
#include "MainUpdate.h"


using namespace std;

//** Input
//
// 


int main(void)
{

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
