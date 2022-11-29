#include <stdio.h>
#pragma warning (disable : 4996)
#include <math.h>
#include <string.h>
#include <windows.h>
#include <winCon.h>
#include <time.h>
#include <conio.h>
#include "extern_메인함수.cpp"


unsigned long dw;//넓이를 반환 할 곳을 선언.
bool check_function = false;//특정 함수에 들어갔는지 체그하는 함수.

//---------------------------------------------------------------------

int omog_position_x = 82, omog_position_y = 15;//오목의 좌표.



// 기능관련 함수.
int move(int x, int y)//출력하는 위치를 바꿔주는 함수,메인함수에서 불러옴
{
	COORD print = { x-1,y-1};//초점을 맞춰 COORD print 에 저장	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), print);
	return 0;
}
void delete_print()//출력화면을 지운다.(공백으로 바꿈)
{
	for (int i = 0; i <= 100; i++)
	{
		FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ', i * i, { 0, 0 }, &dw);//dw  =넓이를 반환할 곳.
		Sleep(20);
	}

	check_function = true;
	move(1, 1);

}
void mini_delete_print(int x,int y)//일정 부분의 출력화면을 지운다.
{
	COORD print = { x - 1,y - 1 };
	FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ', 20 * 3,print, &dw);//dw  =넓이를 반환할 곳.
}
void change_color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// --------------------------------------------------------------

void print_game()//오목게임을 출력해주는 함수
{
	int x = 70, y = 10;//출력할 좌표의 변수 저장.
	move(x,y);
	printf("  ■■    ■■■   ■■■   ■ ■     ■■   ■    \n");
	move(70, 11);
	printf(" ■  ■   ■  ■       ■■ ■ ■    ■  ■  ■    \n");
	move(70, 12);
	printf("  ■■    ■■■       ■   ■ ■     ■■   ■    \n");
	move(70, 13);
	printf("   ■       ■                                     \n");
	move(70, 14);
	printf(" ■■■   ■■■                         ■■■    \n");
	move(70, 15);
	printf("                                         ■  ■    \n");
	move(70, 16);
	printf("          ■■■                         ■■■    \n");
	move(70, 17);
	printf("              ■                                   \n");
	move(70, 18);
	printf("              ■                                   \n");
	move(70, 19);

	move(69, 23);

	for (int a = 69; a <= 118; a++)// "게임 시작"문장주의에 네모난 틀을 만든다.
	{

		printf("-");

		if (a == 118)
		{

			for (int b = 23; b <= 37; b++)
			{
				move(118, b);
				printf("|");
			}
		}
	}
	for (int a = 24; a <= 37; a++)
	{
		move(69, a);
		printf("|");

		if (a == 37)
		{
			for (int b = 69; b <= 118; b++)
			{
				printf("-");
			}
		}
	}

	move(89, 30);
	printf("게임 시작!");
	move(85, 32);
	printf("아무 키나 누르세요..");
	printf("\n\n\n\n\n\n\n\n\n");
	
}

void print_omog()//오목판 출력
{
	//오목판은 15*15의 크기를 지녔다.

	int omog_position_x = 82, omog_position_y = 15;//현재 나의 좌표. 키보드에 따라 좌표가 달라진다.

	for (int a = 0; a <15; a++)//오목판 15*15 로 출력한다.
	{
		move(omog_position_x -4, omog_position_y +a);
		printf("%2d",a);

		for (int b = 0; b <15; b++)
		{
			move(omog_position_x + (b*2), omog_position_y + a);//x축은 2칸이 y축으로 1칸이다.
			printf("□");
		}
	}
	//오목칸의 넓이 x = 82~110, y = 15~29;

	for (int a = 0; a < 15; a++)
	{
		move(omog_position_x +(a*2), 30);
		printf("%c",a+65);
	}







}
void omog_background(bool what_black)//오목 게임 화면의 유저 정보 출력
{
	for (int a = 0; a <=110; a += 110)
	{
		move(8+a, 17);
		printf("ㄴ");
	}
	move(10,16);
	printf("%sㄱ",one_player_name);
	move(120, 16);
	printf("%sㄱ", two_player_name);
	move(10,20);
	printf("승 : %d    패 : 0", point_one);
	move(120, 20);
	printf("승 : %d    패 : 0", point_two);

	if (what_black == 0)
	{
		move(10, 14);
		printf("--흑돌--");


		move(120, 14);
		printf("--백돌--");

	}
	else
	{
		move(10, 14);
		printf("--백돌--");

		move(120, 14);
		printf("--흑돌--");

	}


	
}

void omog_print_myturn(bool what_tern)
{

	if (what_tern == 1)
	{

		mini_delete_print(10, 40);
		move(120, 40);
	}

	else if (what_tern == 0)
	{

		mini_delete_print(120, 40);
		move(10, 40);
	}

	change_color(6);
	printf("///*****당신의 턴!*****///(っ °Д °;)っ(っ °Д °;)っ");

	change_color(7);


}
void omog_error()
{
	move(106, 40);
	change_color(4);

	printf("이미 놓여진 자리입니다!!");

	change_color(7);

}
void print_black_omog()
{
	change_color(0);
	move(omog_position_x, omog_position_y);
	printf("■");
	change_color(7);

}
void print_white_omog()
{
	change_color(8);
	move(omog_position_x, omog_position_y);
	printf("■");
	change_color(7);
}



void omog_keyboard()//오목 키보드
{
	int keyboard_value;//키보드 값을 입력받는다. 방향키를 구분하여 움직인다.


	while (1)//뱡향키 관련 while 함수
	{
		keyboard_value = getch();
		if (keyboard_value == 224)//오목 착수과정을 표시하는 함수 ,방향키
		{

			if (omog_arr_xy[((omog_position_x-80)/2)-1][omog_position_y-15] == 0)
			{
				move(omog_position_x, omog_position_y);
				printf("□");
			}

			keyboard_value = getch();
			switch (keyboard_value)
			{
				
			case 72://↓
				omog_position_y--;
				break;

			case 80://↑

				omog_position_y++;
				break;
			case 75://←

				omog_position_x -= 2;
				break;
			case 77://→

				omog_position_x += 2;
				break;

			}

			
			//82 84 86 88 
			omog_position_x = ((omog_position_x - 82) % 30) + 82;
			omog_position_y = ((omog_position_y - 15) % 15) + 15;
			if (omog_position_x < 82)
			{
				omog_position_x += 30;
			}

			else if (omog_position_y < 15)
			{
				omog_position_y += 15;
			}

			move(omog_position_x, omog_position_y);

			if (omog_arr_xy[((omog_position_x - 80)/2-1)][omog_position_y - 15] == 0)
			{
				printf("▤");
			}
		}

		else if (keyboard_value == 13)//enter 
		{
			break;
		}
	}
}


