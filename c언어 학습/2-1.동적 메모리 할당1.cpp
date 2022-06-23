#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
	int* pi;
	//malloc : 메모리 할당.
	/*
	* 메모리 할당 법
	* 포인터 변수 = (자료형*)malloc(sizeof(자료형));
	*/
	pi = (int*)malloc(sizeof(int));
	*pi = 100;
	if (pi == NULL)
	{
		printf("동적 메모리 할당에 실패하였습니다.");
	}
	else
	{
		printf("%d", *pi);
		//!! 메모리를 할당한 후에 무조건 할당한 메모리를 초기화 시켜야 안정적으로 작동이 가능하다.
		// free : 동적 메모리를 헤제 시키는 함수 free(포인터 변수)로 가능
		free(pi);
	}

	//예제1. 동적 메모리를 이용한 알파벳 출력하기
	char* pc = NULL;
	pc = (char*)malloc(100 * sizeof(char));//char형 즉 1하나의 문자가 100개 들어갈수 았는 공간의 크기를 만듬.
	if (pc == NULL)
	{
		printf("메모리 할당에 실패했습니다\n");
		//exit 프로그램을 종료하게 하는 함수, 참이면 1 거짓이면 0
		exit(1);
	}
	//pc가 가르키는 포인터의 위치를 1씩 증가시키면서 내가 원하는 문자를 넣으면 된다.
	printf("동적 메모리를 이용해서 출력한 알파벳 :\n");
	for (int i = 0; i < 26; i++)
	{
		*(pc + i) = 'a' + i;// pc +i가 가르키는 위치의 값은 ?이다!
		printf("%c ", *(pc + i));
	}
	*(pc + 26) = NULL;//문자열 배열의 마직막이 NULL값이듯이 마지막을 알기 위해서 해준 것
	free(pc);


	//예제2.정수 5개를 동적 메모리 할당을 이용하여 처리하기
	int* p;
	p = (int*)malloc(5*sizeof(int));
	if (p == NULL)
	{
		printf("동적 메모리 할당에 실패하였습니다");
		exit(1);
	}
	p[0] = 100;
	p[1] = 200;
	p[2] = 300;
	p[3] = 400;
	p[4] = 500;

	for (int a = 0; a < 5; a++)
	{
		printf("%d\n",*(p+a));
	}
	free(p);

	

}
	





