#pragma warning (disable : 4996)
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <windows.h>

/*
    void Gotxy(int x, int y)//���ϴ� ��ġ�� ����ϴ� �Լ�.
    {
        //COORD =  ����ü�̸� ����Ǿ� �ִ� x,y�� ���� �������ִ� ����̴�.

        COORD Pos = { y-1,x-1}; // ��µǴ� ��ġ�� (1,1)�̹Ƿ� (0,0)���� �����ִ� �۾��̴�.

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);// ����� ��ġ�� pos�� x,y������ �̵���Ų��.
    }
    void main()
    {
        Gotxy(4, 20);
        printf("���\n");
        system("pause");
    }
*/

// Ȱ�� ���� ����� ���� ��� �����.
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

