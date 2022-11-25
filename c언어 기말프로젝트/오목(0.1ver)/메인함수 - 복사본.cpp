#include <stdio.h>
#pragma warning (disable : 4996)
#include <math.h>
#include <string.h>
#include <windows.h>
#include <winCon.h>
#include <conio.h>
#include <time.h>

typedef int check;
//extern-----------------------------------------------------------------
extern int omog_position_x;
extern int omog_position_y;



//extern!!//---funtion()------------------------------------------------
void print_game();//외부프로그램 (출력함수) 파일에서 불러온 함수.
void delete_print();
void print_omog();
void omog_keyboard();
void omog_background();
int move(int x,int y);




struct player//플레이어 이름과 점수
{
	char player_name[10] = { 0 };
	int point = 0;
};

int playomog()
{
	player one, two;

	srand(time(NULL));//매번마다 랜덤으로 값이 나오게 된다. 흑백을 정할때 사용된다.

	int turn_select = (rand()%2);

	//플레이어 정보 입력
	printf("플레이어 1의 이름을 입력하세요. : ");
	scanf("%s", &one.player_name);

	printf("플레이어 2의 이름을 입력하세요. : ");
	scanf("%s", &two.player_name);

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
		printf("%s 입니다!\n",two.player_name);
	}
	else if(turn_select == 0)
	{
		printf("%s 입니다!\n", one.player_name);
	}

	return turn_select;
}
/*

오목판을 15*15로 출력한 후 배열로도 15*15로 만든다.

turn 이라는 정수를 만든 후 player1부터 시작.

*turn은 rand()를 이용하여 누가 먼저 할지 정한다.
* 
* 착수과정에서 오목 판을 벗어나면 안되고 또한 enter를 누르면 나의 돌이 착수가 되며 배열에 저장한다.
*배열에 저장될때 만약 오목이 되면 게임을 이겼다는 결과창을 출력한 뒤 게임을 더 할건지 물어 오목게임을 반복한다. 




*/

int main(void)//메인 함수
{

	int turn = 1;

	print_game();
	int omog_arr_xy[15][15] ={0};//오목판을 숫자로 나타낸다. 착수시 자리 위치랑 오목 판별등에 사용된다.
	
	char game_start = getch();
	delete_print();

	//사용자의 정보를 입력한다.
	bool turn_check = playomog();

	Sleep(500);
	printf("\n\n게임을 시작합니다. 아무키나 눌러주세요..\n");

	game_start = getch();


	delete_print();

	//게임시작!
	print_omog();//오목판을 깔아줌

	omog_background();//배경을 깔아줌


	// 착수 과정

	omog_keyboard();//착수할때 사용하는 함수.





}



