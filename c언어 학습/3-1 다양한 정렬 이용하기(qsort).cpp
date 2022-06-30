#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//�����Լ� qsort �̿��ϱ� 

int arr[1000000] = { 0 };



//const�� ����� �츮�� �����ϴ� �����ʹ� �޸� �� ���� �ٲ��� �ʴ´ٴ� ���� �ִ�
//���� : �ڷ��� ��,�ڿ� ���
//++ �ڷ��� �տ� ����ϸ� �������� ���� �ٲ� �� ���� , �ڷ��� �ڿ� ����ϸ� �������� ��ġ�� �ٲ� �� ����. 
int compare(const void* a, const void* b)//�� �Լ�, qsort�� ����ϱ� ���ؼ��� �� �ʿ��ϴ�.
{
	int num1 = *(int*)a;
	int num2 = *(int*)b;

	if (num1 > num2)//���� ���� �����̸� return 1�� ������ ���������̸� return -1�� ��ȯ�ؾ� �Ѵ�.
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
	//qsort = �迭�� �������� �Ǵ� ������������ �������ִ� ���α׷����� �������ĺ��� �ξ� ������ ����ϱⰡ ���� ��ƴ�.
	//���� : qsort(������ �� �迭�� �̸�,   �迭�� ����(sizeof(�迭�� �̸�)) / sizeof(�迭�� ũ��)    ,   �迭�� ũ��(int�� sizeof(int) �̷�������)   ,���Լ��� �̸�);
	qsort(arr, sizeof(arr) / sizeof(int), sizeof(int), compare);//���� ����
	for (int a = 0; a < n; a++)
	{
		printf("%d\n",arr[a]);
	 }
}



