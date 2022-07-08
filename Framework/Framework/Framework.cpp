// ** Framework v6.2
#define _CRT_SECURE_NO_WARNINGS
#include "Headers.h"
#include "MainUpdate.h"


// list는 주소값만 복사해서 넘겨준다.
// 

// 선생님이 설명하는 코드는 key값으로 넘겨줄 것이다.

//** 동적과 정적의 차이
/*
 동적은 주소를 바꿀 수 있다.
 정적은 주소가 바뀌지 않는다. (정적화)  << 프로그램이 시작될 때 데이터를 계속 불러올 것이다.
 즉, 런타임 내내 들고있기 때문에 
 런타임이 오래 걸린다. 쓰고 싶다고해서 쓰는것이 아니다. 효율적으로 써야하기 때문에.
 static은 조심해서 사용해야한다. 많을수록 어디가 문제가 있는지 파악하기 어려우므로
 위험할 수도 있다.
*/


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

/*
    BBB b;
    b.Number = 10;
    b.Num = 100;

    CCC c;
    c.Number = 100;
    c.Num = 1000;

    cout << b.Number << endl;
    cout << c.Number << endl;

    cout << b.Num << endl;
    cout << c.Num << endl;

*/
// 두개의 버퍼(더블버퍼)를 사용하면 깜빡이는 현상을 유저가 볼 수 없다.
// 첫 번째가 업데이트된 후 두 번째가 나올때 미리 만들어진 것을 가져오고
// 첫 번째는 삭제되고 다시 불러올때 만들어서 다음 버퍼에 나오는 방식
// 정면에 띄우는 버퍼를 정면버퍼, 후면에 띄우는 버퍼를 후면버퍼라 한다.