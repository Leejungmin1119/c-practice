#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define bit 32
int main(void)
{
	//정수의 2의 보수 계산 구현 코드

	int integer;//int형 변수 지정
	scanf("%d", &integer);
	for (int check = bit - 1; check >= 0; check--)
	{
		printf("%d ", (integer >> check) & 1);
		
	}
}