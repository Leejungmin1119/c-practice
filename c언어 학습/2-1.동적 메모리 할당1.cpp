#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
	int* pi;
	//malloc : �޸� �Ҵ�.
	/*
	* �޸� �Ҵ� ��
	* ������ ���� = (�ڷ���*)malloc(sizeof(�ڷ���));
	*/
	pi = (int*)malloc(sizeof(int));
	*pi = 100;
	if (pi == NULL)
	{
		printf("���� �޸� �Ҵ翡 �����Ͽ����ϴ�.");
	}
	else
	{
		printf("%d", *pi);
		//!! �޸𸮸� �Ҵ��� �Ŀ� ������ �Ҵ��� �޸𸮸� �ʱ�ȭ ���Ѿ� ���������� �۵��� �����ϴ�.
		// free : ���� �޸𸮸� ���� ��Ű�� �Լ� free(������ ����)�� ����
		free(pi);
	}

	//����1. ���� �޸𸮸� �̿��� ���ĺ� ����ϱ�
	char* pc = NULL;
	pc = (char*)malloc(100 * sizeof(char));//char�� �� 1�ϳ��� ���ڰ� 100�� ���� �Ҵ� ������ ũ�⸦ ����.
	if (pc == NULL)
	{
		printf("�޸� �Ҵ翡 �����߽��ϴ�\n");
		//exit ���α׷��� �����ϰ� �ϴ� �Լ�, ���̸� 1 �����̸� 0
		exit(1);
	}
	//pc�� ����Ű�� �������� ��ġ�� 1�� ������Ű�鼭 ���� ���ϴ� ���ڸ� ������ �ȴ�.
	printf("���� �޸𸮸� �̿��ؼ� ����� ���ĺ� :\n");
	for (int i = 0; i < 26; i++)
	{
		*(pc + i) = 'a' + i;// pc +i�� ����Ű�� ��ġ�� ���� ?�̴�!
		printf("%c ", *(pc + i));
	}
	*(pc + 26) = NULL;//���ڿ� �迭�� �������� NULL���̵��� �������� �˱� ���ؼ� ���� ��
	free(pc);


	//����2.���� 5���� ���� �޸� �Ҵ��� �̿��Ͽ� ó���ϱ�
	int* p;
	p = (int*)malloc(5*sizeof(int));
	if (p == NULL)
	{
		printf("���� �޸� �Ҵ翡 �����Ͽ����ϴ�");
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
	





