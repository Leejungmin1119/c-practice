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

	printf("�÷��̾� 1�� �̸��� �Է��ϼ���. : ");
	scanf("%s", &one.player_name);

	printf("�÷��̾� 2�� �̸��� �Է��ϼ���. : ");
	scanf("%s", &two.player_name);

	printf("\n\n������ �����մϴ�.");



}


