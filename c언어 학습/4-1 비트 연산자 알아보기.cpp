#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define bit 32
int main(void)
{
	//다양한 비트 연산자 알아보기.

	/*
		for (int check = 7; check >= 0; check--)
		{
			printf("%d ", (flag << check) & 1);
		}
	*/
	//비트 연산자
	int a;
	int b;
	char symbol[3];
	printf("비트 연산할 두 변수를 지정해주세요. : ");
	scanf("%d %d", &a,&b);//비트 연산을 이용할 두 변수 입력받기

	printf("비트 연산자를 입력해주세요.");
	scanf("%s", &symbol);

	//1, &연산  (and)
	//a & b == a 와 b를 비트로 and 연산한다
	//ex) 0000 1001(9) & 0000 0011(3) == 0000 0001(1)
	if (symbol[0] == '&')
	{
		printf("%d", a & b);
	}

	//2. |연산 (or)
	//a & b == a 와 b를 비트로 or 연산한다
	//ex) 0000 1001(9) & 0000 0011(3) == 0000 1011(11)
	if (symbol[0] == '|')
	{
		printf("%d", a | b);

	}
	//3.^연산 (xor)
	//a & b == a 와 b를 비트로 xor 연산한다
	//ex) 0000 1001(9) & 0000 0011(3) == 0000 1010(10)
	if (symbol[0] == '^')
	{
		printf("%d", a ^ b);
	}

	//4. ~연산(not)
	//헤당 비트를 뒤집는다(0은 1로, 1은 0으로)
	//ex) 0000 1001(9) 1111 0110
	if (symbol[0] == '~')
	{
		printf("~a = %d, ~b= %d", ~a, ~b);
	}

	//5. << ,>> 연산
	//헤당비트를 왼쪽 또는 오른쪽으로 b만큼 a의 비트를 이동시킨다.
	//ex) 0000 1001 >> 4 == 1001 
	if (symbol == ">>")
	{
		printf("%d", a >> b);
	}

}