#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//���� �޸� �Ҵ� Ȱ���� 2,


int main(void)//���� �Լ�
{
	//2.2���� �迭�� �̿��� ���� �޸� �Ҵ�!
	int** a;
	//������ �ȿ� �������� ������ �迭�� �־ ���� �޸𸮸� �Ҵ������� �Ѵ�.
	a = (int**)malloc(10 * (sizeof(int*)));//1���� ���� �޸𸮸� �Ҵ��Ų��.
	for (int b = 0; b < 10; b++)
	{
		*(a+b) = (int*)malloc(10 * sizeof(int));//2���� �迭�� ���� �޸𸮸� �Ҵ��Ų��.
	}
	for (int b = 1; b < 10; b++)
	{
		for (int c = 1; c < 10; c++)
		{
			*(*(a + c) + b) = b * c;// *(����) == 1���� , *(*())//2����
			printf("%d x %d = %d\n",b,c, *(*(a + c) + b));
		}
	}
	for (int b = 0; b < 10; b++)
	{
		free(*(a + b));//1������ ���� �Ҵ� �޸𸮸� ���� ���� �Ѵ�.
	}
	

}





