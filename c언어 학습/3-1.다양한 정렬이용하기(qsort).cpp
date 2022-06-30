#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int arr[1000000] = { 0 };
int compare(const void* a, const void* b)//비교 함수 생성
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
	//사용법 : qsort
	qsort(arr, sizeof(arr) / sizeof(int), sizeof(int), compare);
	for (int a = 0; a < n; a++)
	{
		printf("%d\n",arr[a]);
	 }
	sort(arr, arr + 19);
}



