#pragma warning (disable : 4996)
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <windows.h>

//exturn : �ٸ� ���α׷� ���Ͽ��� ����� ������ �ܺ� �Լ��� ����ٰ� ���� �ִ�.

//extrun�� ������ �����ϰ� �����ϱ� ���ؼ��� ������ �ٸ� ���Ͽ� �� ������ ������ �Ǿ��־�߸� �Ѵ�.

//  ���� ��� : exturn (�ڷ���) (����,�Լ���)

//system : windows.h �ش� ������ �ҷ��ͼ� ���
void main()
{
	//system : windows.h �ش� ������ �ҷ��ͼ� ���

	system("tiTle �ܼ�â �ٹ̱�");//cmd�� ������ ����.
	system("color 2f");//cmd ������ ����.
	
	//sleep() �����ܴٶ�� ������ ����� �����̸� �ɾ��ش�.

	for (int a = 0; a < 3; a++)
	{
		printf("%d..\n", a+1);
		Sleep(1000);

	}
	system("color 64");
}