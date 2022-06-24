#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//동적 메모리 할당 활용편 2,


int main(void)//메인 함수
{
	//2.2차원 배열을 이용한 동적 메모리 할당!
	int** a;
	//포인터 안에 여러개의 포인터 배열을 넣어서 동적 메모리를 할당시켜줘야 한다.
	a = (int**)malloc(10 * (sizeof(int*)));//1차원 동적 메모리를 할당시킨다.
	for (int b = 0; b < 10; b++)
	{
		*(a+b) = (int*)malloc(10 * sizeof(int));//2차원 배열의 동적 메모리를 할당시킨다.
	}
	for (int b = 1; b < 10; b++)
	{
		for (int c = 1; c < 10; c++)
		{
			*(*(a + c) + b) = b * c;// *(변수) == 1차원 , *(*())//2차원
			printf("%d x %d = %d\n",b,c, *(*(a + c) + b));
		}
	}
	for (int b = 0; b < 10; b++)
	{
		free(*(a + b));//1차원에 동적 할당 메모리를 전부 헤제 한다.
	}
	

}





