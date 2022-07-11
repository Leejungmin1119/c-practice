#pragma warning(disable :4996)
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
	//블랙잭 구현하기


	/*
	
		코드 요약

		1.for문 선언(21이 넘으면 빠져나감)
		{


			2.카드뽑기.

			3.뽑은 카드수 출력후 다시 for문의 초기부분으로 돌아감.

			4.다시 돌아와서 더 할 것인지 안할 것인지 선택후 끝날때 까지 반복


		}

			5.만약 21이상이면 패배출력 21이하면 그수를 출력한다.

	
	*/

	int max = 21;//블랙잭에서 넘어야 하면 안되는 수를 정해놓는다.

	int player_result = 0; int player_card[10] = { 0 };// 나의 카드의 총합 , 각각 내가 얻은 카드의 숫자들을 저장해놓는 배열 
	int turn = 0;//턴(라운드).

	char choice =0;//선택할때 쓰이는 문자 선언

	srand(time(NULL));//경우의 수 초기화 시켜 매번 나오는 카드가 다르게 한다.

	
	printf("블랙잭 게임을 시작합니다!\n");
	for (; player_result <= 21 && choice != 'n' && choice != 'N'; turn++)
	//21이 넘을때 까지 for함수를 계속 이용하게 한다 또한 사용자가 카드를 뽑은 뒤 그만할 수도 있다.
	{
		if (turn != 0)//첫번째 턴이 아닌 2반쩨 이상의 턴이면 그만할 수 있는 선택권을 준다.
		{
			printf("현재 당신의 카드 총합은 %d이고, %d 이상을 뽑으면 패배입니다.\n 계속하시겠습니까? (y/n) : \n",player_result,max-player_result);
			
			scanf("%c", &choice);
			getchar();

			if (choice == 'n' && choice == 'N')//만약 n또는 N을 선택한다면 for문을 빠져나와 게임을 끝내도록 한다.
			{
				continue;
			}
		}
		printf("%d번째 턴! 카드를 뽑습니다.\n", turn);

		player_card[turn - 1] = (rand() % 10) + 1;
		/*
		난수를 생성하는 rand 함수를 이용하여 랜덤한 수를 뽑게 하고 그 후 +1를 하여 1~10에 수를 뽑게 만들어 준다.

		만약 +1을 안하게 된다면 rand에서 10의 배수의 숫자가 나올때 나머지가 0이기 때문에 
		0이라는 숫자가 나올것이고, 이를 막기 위해 사용한다.
		*/

		printf("뽑은 카드의 수는.. %d입니다.", player_card[turn - 1]);

		player_result += player_card[turn - 1];

	}

	
	if (player_result > 21)
	{
		printf("현재 키드의 총합은 %d 이므로\n",player_result);
		printf("game over!");
		return 0;
	}
	else if (player_result <= 21)
	{
		printf("나의 카드의 총합은  = %d 입니다!",player_result);
		return 0;
	}

}
