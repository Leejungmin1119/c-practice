#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define bit 32
int main(void)
{
	//�پ��� ��Ʈ ������ �˾ƺ���.

	/*
		for (int check = 7; check >= 0; check--)
		{
			printf("%d ", (flag << check) & 1);
		}
	*/
	//��Ʈ ������
	int a;
	int b;
	char symbol[3];
	printf("��Ʈ ������ �� ������ �������ּ���. : ");
	scanf("%d %d", &a,&b);//��Ʈ ������ �̿��� �� ���� �Է¹ޱ�

	printf("��Ʈ �����ڸ� �Է����ּ���.");
	scanf("%s", &symbol);

	//1, &����  (and)
	//a & b == a �� b�� ��Ʈ�� and �����Ѵ�
	//ex) 0000 1001(9) & 0000 0011(3) == 0000 0001(1)
	if (symbol[0] == '&')
	{
		printf("%d", a & b);
	}

	//2. |���� (or)
	//a & b == a �� b�� ��Ʈ�� or �����Ѵ�
	//ex) 0000 1001(9) & 0000 0011(3) == 0000 1011(11)
	if (symbol[0] == '|')
	{
		printf("%d", a | b);

	}
	//3.^���� (xor)
	//a & b == a �� b�� ��Ʈ�� xor �����Ѵ�
	//ex) 0000 1001(9) & 0000 0011(3) == 0000 1010(10)
	if (symbol[0] == '^')
	{
		printf("%d", a ^ b);
	}

	//4. ~����(not)
	//��� ��Ʈ�� �����´�(0�� 1��, 1�� 0����)
	//ex) 0000 1001(9) 1111 0110
	if (symbol[0] == '~')
	{
		printf("~a = %d, ~b= %d", ~a, ~b);
	}

	//5. << ,>> ����
	//����Ʈ�� ���� �Ǵ� ���������� b��ŭ a�� ��Ʈ�� �̵���Ų��.
	//ex) 0000 1001 >> 4 == 1001 
	if (symbol == ">>")
	{
		printf("%d", a >> b);
	}

}