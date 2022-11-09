#include <stdio.h>
#pragma warning (disable :4996)
#include <stdlib.h>
struct player
{
	char player_name[10] = {0};
	int point = 0;
};
int main()
{
	player one, two;

	printf("플레이어 1의 이름을 입력하세요. : ");
	scanf("%s", &one.player_name);

	printf("플레이어 2의 이름을 입력하세요. : ");
	scanf("%s", &two.player_name);

	printf("\n\n게임을 시작합니다.");



}


