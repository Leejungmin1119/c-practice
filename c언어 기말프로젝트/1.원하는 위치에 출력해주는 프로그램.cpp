#pragma warning (disable : 4996)
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <windows.h>

/*
    void Gotxy(int x, int y)//원하는 위치에 출력하는 함수.
    {
        //COORD =  구조체이며 선언되어 있는 x,y의 값을 저장해주는 방식이다.

        COORD Pos = { y-1,x-1}; // 출력되는 위치가 (1,1)이므로 (0,0)으로 맞춰주는 작업이다.

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);// 출력의 위치를 pos의 x,y값으로 이동시킨다.
    }
    void main()
    {
        Gotxy(4, 20);
        printf("출력\n");
        system("pause");
    }
*/

// 활용 문제 출력을 통한 계단 만들기.
void move(int x, int y)
{
    COORD print = {x,y};

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), print);
}
void main()
{
    int work;
    int x, y;
    scanf("%d", &work);

    for (int a = 0; a < work; a++)
    {
        x = a, y = a;
        move(x, y);
        printf("|_");
    }
    system("pause");
}

