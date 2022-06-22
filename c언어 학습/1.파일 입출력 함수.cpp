#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
	//fp = 파일 변수의 이름	

	//1 "w" : 쓰기전용
	FILE* fp = NULL;//fp = 파일 변수의 이름	

	//fopen 함수 => 파일 열기에 실패시 NULL 값 반환.

	//fopen의 기능들// (파일 변수의 이름) = fopen("파일의 이름 or 만들어진 이름.txt","내가 이용할 모드(쓰기 모드,읽기모드등)");
	/*
		"r" : 읽기전용(파일이 있어야 가능)

		"w" : 쓰기전용(파일 필요 X)

		"a" : 추가(파일이 있다면 끝을 추가하고, 파일이 없다면 파일을 생성시킨다.)
	*/

	fp = fopen("output.txt", "w");
	if (fp == NULL)
	{
		printf("파일열기에 실패하였습니다.");
	}
	else
	{
		printf("파일 열기에 성공하였습니다.");
	}
	//fputc = FILE put char : 파일에 캐릭터형의(char형) 문자를 놓는다. => 문자 한개를 놓는다는 소리임.
	//사용법 : fputc('놓을 문자',파일 변수 이름);
	fputc('H', fp);
	fputc('E', fp);
	fputc('L', fp);
	fputc('L', fp);
	fputc('O', fp);
	//fclose : 내가 지정한 파일을 닫게 해주는 함수// fclose(파일 변수 이름);

	fclose(fp);
	//디버그를 한 후 파일에 들어가 보면 파일이 생성되있고 그곳에 내가 원하는 글이 적혀있다면 성공.
	// or 파일 열기에 실패하였습니다가 출력이 될 것이다. 

	//2. "r" 읽기 모드
	int c;
	FILE* p = fopen("read.txt", "r");

	if (p == NULL)
	{
		printf("파일열기에 실패하였습니다");

	}
	else
	{
		printf("파일열기에 성공하였습니다\n");
	}
	//fgetc : 내가 원하는 파일을 열어 하나하나 읽어서 저장한다는 것임//
	//사용법 : 변수 = fgetc(파일 변수 이름) != EOF

	//putchar : 읽어서 출력하게 하는 함수
	//사용법 : putchar(fgetc를 저장한 함수)
	while ((c = fgetc(p)) != EOF)//파일의 끝까지 출력한다는 말임
	{
		putchar(c);
	}
	//3.단어 검색 ("r" 활용)

	FILE* j = NULL;
	char word[256];//찾을 파일의 단어를 저장하는 배열
	char file[256];//찾을 파일의 이름을 저장하는 배열
	char buffer[256];//파일에 있는 내용들을 저장하는 배열
	int line = 0;
	printf("단어를 찾을 파일을 적어주세요.\n");
	
	scanf("%s", &file);

	printf("찾을 단어를 적어주세요.\n");
	scanf("%s", &word);
	j = fopen(file, "r");
	if (j == NULL)
	{
		//fprintf :출력할때 해당 파일에 출력하는 함수중 하나이다.
		//사용법 : fprintf(파일 변수 이름,"적을 내용");
		fprintf(stderr,"파일이 존재하지 않습니다.");
	}
	else
	{
		//fgets  : 해당 변수나 배열에 정해진 내용을 옮겨주는 함수
		//사용법 : fgets(저장할 함수,길이,파일 변수 이름)
		while (fgets(buffer, 256, j))
		{
			line++;
			//strstsr = 내 파일에 필요한 단어가 았는지 찾아주는 함수, include <string.h> 해더파일 필요하다.
			//사용법 : strstr(내용이 저장된 배열의 이름, 저장된 단어)
			if (strstr(buffer, word))
			{
				printf("%d줄에 단어 %s가 발견되었습니다\n", line, word);
			}
		}
	}
	fclose(j);
}	
	





