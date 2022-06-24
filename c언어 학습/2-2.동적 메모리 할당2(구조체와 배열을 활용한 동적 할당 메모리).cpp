#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//동적 메모리 할당 활용편 2,

//1,구조체를 이용한 동적 메모리 할당!
struct book//구조체 설정
{
	char bookname[100];
	int number;

};
void print(struct book* p)//사용자 지정 함수
{
	for (int a = 0; a < 2; a++)
	{
		printf("책 번호 : %d ,책 이름 : %s\n", p[a].number, p[a].bookname);
	}
}
int main(void)//메인 함수
{
	struct book*p;//구조체 포인터 변수를 지정한다
	p = (struct book*)malloc(2 * sizeof(struct book));//구조체를 동적할당하여 2개의 구조체가 들어가는 메모리 공간을 생성한다.
	
	if (p == NULL)
	{
		printf("동적 할당에 실패하였습니다.");
	}
	p[0].number = 1;
	p[1].number = 65;
	strcpy(p[0].bookname, "c언어 프로그래밍");//구조체에게 문자열을 적용하기 위해서는 strcpy를 이용하여 넣어야 한다.
	strcpy(p[1].bookname, "unity 기초");
	print(p);//사용자 지정 함수를 실행시켜 지정해놓은 구조체 동적 메모리를 출력하는 시스템을 만든다.
	free(p);

}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

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





