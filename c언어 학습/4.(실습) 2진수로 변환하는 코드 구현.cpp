#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define bit 32
int main(void)
{
	//������ 2�� ���� ��� ���� �ڵ�

	int integer;//int�� ���� ����
	scanf("%d", &integer);
	for (int check = bit - 1; check >= 0; check--)
	{
		printf("%d ", (integer >> check) & 1);
		
	}
}