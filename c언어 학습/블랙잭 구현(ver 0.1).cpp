#pragma warning(disable :4996)
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
	//���� �����ϱ�


	/*
	
		�ڵ� ���

		1.for�� ����(21�� ������ ��������)
		{


			2.ī��̱�.

			3.���� ī��� ����� �ٽ� for���� �ʱ�κ����� ���ư�.

			4.�ٽ� ���ƿͼ� �� �� ������ ���� ������ ������ ������ ���� �ݺ�


		}

			5.���� 21�̻��̸� �й���� 21���ϸ� �׼��� ����Ѵ�.

	
	*/

	int max = 21;//���迡�� �Ѿ�� �ϸ� �ȵǴ� ���� ���س��´�.

	int player_result = 0; int player_card[10] = { 0 };// ���� ī���� ���� , ���� ���� ���� ī���� ���ڵ��� �����س��� �迭 
	int turn = 0;//��(����).

	char choice =0;//�����Ҷ� ���̴� ���� ����

	srand(time(NULL));//����� �� �ʱ�ȭ ���� �Ź� ������ ī�尡 �ٸ��� �Ѵ�.

	
	printf("���� ������ �����մϴ�!\n");
	for (; player_result <= 21 && choice != 'n' && choice != 'N'; turn++)
	//21�� ������ ���� for�Լ��� ��� �̿��ϰ� �Ѵ� ���� ����ڰ� ī�带 ���� �� �׸��� ���� �ִ�.
	{
		if (turn != 0)//ù��° ���� �ƴ� 2���� �̻��� ���̸� �׸��� �� �ִ� ���ñ��� �ش�.
		{
			printf("���� ����� ī�� ������ %d�̰�, %d �̻��� ������ �й��Դϴ�.\n ����Ͻðڽ��ϱ�? (y/n) : \n",player_result,max-player_result);
			
			scanf("%c", &choice);
			getchar();

			if (choice == 'n' && choice == 'N')//���� n�Ǵ� N�� �����Ѵٸ� for���� �������� ������ �������� �Ѵ�.
			{
				continue;
			}
		}
		printf("%d��° ��! ī�带 �̽��ϴ�.\n", turn);

		player_card[turn - 1] = (rand() % 10) + 1;
		/*
		������ �����ϴ� rand �Լ��� �̿��Ͽ� ������ ���� �̰� �ϰ� �� �� +1�� �Ͽ� 1~10�� ���� �̰� ����� �ش�.

		���� +1�� ���ϰ� �ȴٸ� rand���� 10�� ����� ���ڰ� ���ö� �������� 0�̱� ������ 
		0�̶�� ���ڰ� ���ð��̰�, �̸� ���� ���� ����Ѵ�.
		*/

		printf("���� ī���� ����.. %d�Դϴ�.", player_card[turn - 1]);

		player_result += player_card[turn - 1];

	}

	
	if (player_result > 21)
	{
		printf("���� Ű���� ������ %d �̹Ƿ�\n",player_result);
		printf("game over!");
		return 0;
	}
	else if (player_result <= 21)
	{
		printf("���� ī���� ������  = %d �Դϴ�!",player_result);
		return 0;
	}

}
