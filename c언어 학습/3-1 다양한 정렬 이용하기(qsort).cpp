#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//정렬함수 qsort 이용하기 

int arr[1000000] = { 0 };



//const는 상수로 우리가 선언하는 변수와는 달리 그 값이 바뀌지 않는다는 점이 있다
//사용법 : 자료형 앞,뒤에 사용
//++ 자료형 앞에 사용하면 포인터의 값을 바꿀 수 없고 , 자료형 뒤에 사용하면 포인터의 위치를 바꿀 수 없다. 
int compare(const void* a, const void* b)//비교 함수, qsort를 사용하기 위해서는 꼭 필요하다.
{
	int num1 = *(int*)a;
	int num2 = *(int*)b;

	if (num1 > num2)//만약 오름 차순이면 return 1이 맞지만 내림차순이면 return -1을 반환해야 한다.
	{
		return 1;
	}
	else if (num1 < num2)
	{
		return -1;
	}
	else if (num1 == num2)
	{
		return 0;
	}

}
int main(void)
{
	int n;
	scanf("%d", &n);
	for (int a = 0; a < 1000000; a++)
	{
		arr[a] = 1000001;
	}
	for (int a = 0; a < n; a++)
	{
		scanf("%d", &arr[a]);
	}
	//qsort = 배열을 오름차순 또는 내림차순으로 정렬해주는 프로그램으로 버블정렬보다 훨씬 빠르나 사용하기가 비교적 어렵다.
	//사용법 : qsort(정렬을 할 배열의 이름,   배열의 갯수(sizeof(배열의 이름)) / sizeof(배열의 크기)    ,   배열의 크기(int면 sizeof(int) 이런식으로)   ,비교함수의 이름);
	qsort(arr, sizeof(arr) / sizeof(int), sizeof(int), compare);//실제 사용법
	for (int a = 0; a < n; a++)
	{
		printf("%d\n",arr[a]);
	 }
}



