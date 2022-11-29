#include <stdio.h>
#pragma warning (disable : 4996)
#include <math.h>
#include <string.h>
#include <windows.h>
#include <winCon.h>
#include <conio.h>
#include <time.h>
#include "extern_출력함수.cpp"

//extern-----------------------------------------------------------------

//각 플레이어의 이름
char one_player_name[30] = { 0 };
char two_player_name[30] = { 0 };

//각 플레이어의 점수
int point_one = 0;
int point_two = 0;

int turn = 1;//전체 턴
int omog_arr_xy[30][30] = { 0 };//오목판을 숫자로 나타낸다. 착수시 자리 위치랑 오목 판별등에 사용된다.
int check_omog = 0;

bool win = 0;
bool turn_check;
bool what_black;

int omog_check_up();

int playomog()//플레이어의 정보입력,오목 누가 흑백인지 실행하는 함수이다.
{


	srand(time(NULL));//매번마다 랜덤으로 값이 나오게 된다. 흑백을 정할때 사용된다.

	int turn_select = (rand()%2);

	//플레이어 정보 입력
	printf("플레이어 1의 이름을 입력하세요. : ");
	gets_s(one_player_name);

	printf("플레이어 2의 이름을 입력하세요. : ");
	gets_s(two_player_name);

	Sleep(100);
	printf("흑돌은..");
	for (int a = 1; a <= 3; a++)
	{
		printf("%d ",a);
		Sleep(500);
	}

	//turn의 값에 따라 흑백이 나뉜다.
	if (turn_select == 1)
	{
		printf("%s 입니다!\n",two_player_name);
	}
	else if(turn_select == 0)
	{
		printf("%s 입니다!\n", one_player_name);
	}

	return turn_select;
}
int check_win()
{

	return 0;
}

int main(void)//메인 함수
{

	

	print_game();
	
	char game_start = getch();
	delete_print();

	//사용자의 정보를 입력한다.
	 turn_check = playomog();

	 what_black = turn_check;

	Sleep(500);
	printf("\n\n게임을 시작합니다. 아무키나 눌러주세요..\n");

	game_start = getch();


	delete_print();

	//게임시작!
	print_omog();//오목판을 깔아줌

	omog_background(what_black);//배경을 깔아줌




	while (win == 0)
	{
		// 착수 과정
		omog_print_myturn(turn_check);//누가 착수해야된는지 그림으로 출력한다.
		omog_keyboard();//착수할때 사용하는 함수.


		if (omog_check_up() == 1)
		{
			turn++;
			turn_check = ((turn_check + 1) % 2);
		}

	}
	//승리 후 



}



