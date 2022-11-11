#pragma warning (disable : 4996)
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <windows.h>

//exturn : 다른 프로그램 파일에서 사용이 변수나 외부 함수를 끌어다가 쓸수 있다.

//extrun은 생략이 가능하고 선언하기 위해서는 무조건 다른 파일에 이 변수가 선언이 되어있어야만 한다.

//  선언 방식 : exturn (자료형) (변수,함수명)

//system : windows.h 해더 파일을 불러와서 사용
void main()
{
	//system : windows.h 해더 파일을 불러와서 사용

	system("tiTle 콘솔창 꾸미기");//cmd의 제목을 변경.
	system("color 2f");//cmd 색상을 변경.
	
	//sleep() 잠을잔다라는 것으로 잠깐의 딜레이를 걸어준다.

	for (int a = 0; a < 3; a++)
	{
		printf("%d..\n", a+1);
		Sleep(1000);

	}
	system("color 64");
}