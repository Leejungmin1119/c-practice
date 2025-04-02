#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 100
typedef struct index
{
    int y;
    int x;
}index;

typedef struct Stack
{
    // 스택 크기
    index arr[MAX_SIZE];
    int top;//위치
}Stack;

void init_stack(Stack *s,index *i)
{
    // 초기값 선언
    s->top = -1;
    i->y = 1;
    i->x = 0;

}
void push(Stack *s,index i)
{
    //구조체 배열에 y와 x값을 저장
    s->arr[++(s->top)] = i;
}
index pop(Stack *s)
{
    return s->arr[(s->top)--];
}
bool is_empty(Stack *s)
{
    if(s->top == -1){return true;} 
    return false;

}
bool is_full(Stack *s)
{
    if(s->top == MAX_SIZE-1) {return false;}
    return true;
}


void push_loc(char maze[MAX_SIZE][MAX_SIZE],Stack *s,int y,int x)
{
    // 0 = 갈 수 있는 길
    index newroad = {y,x};
    if (maze[y][x] == '0')
    {
        //간 길 표시하기
        maze[y][x] = '.';
        push(s,newroad);
    }
    else if (maze[y][x] == 'x')
    {
        push(s,newroad);
    }
}
int main()
{
    // 구조체 포인터를 생성하기
    Stack s;
    index i;
    int num,y,x; // num : 크기 , r = 이동할 행 , c = 이동할 열

    scanf("%d",&num);

    /* 왜 r과 c를 선언해야 하는가?
    r 과 c는 각각 행과 열을 뜻하는데 이것을 사용하지 않고 직접 i.r , i.c로 하면
    갈 수있는 길이 2개 이상일때, 길이 덮어씌워지게 되면서 오류가 발생한다.

    즉 r 과 c를 생성하여 끝나기 전까지 기존 위치를 덮어씌우는 오류를 방지한다.
    */
    char maze[MAX_SIZE][MAX_SIZE];

    
    //입력
    for(int i =0;i<num;i++)
    {
        for(int j =0;j<num;j++)
        {
            scanf(" %c",&maze[i][j]);
        }
    }

    //초기값 설정
    init_stack(&s,&i);

    //미로 찾기
    while (maze[i.y][i.x] != 'x')
    {
        y = i.y;
        x = i.x;
    
        push_loc(maze,&s,y+1,x);
        push_loc(maze,&s,y-1,x);
        push_loc(maze,&s,y,x-1);
        push_loc(maze,&s,y,x+1);

        // x를 찾기도 전에 스택이 비면 미로를 탈출을 못한다는 소리이다.
        if (is_empty(&s))
        {
            printf("fail");
            return 0;
        }
        else
        {
            i = pop(&s);
        }
    }

    printf("success");
    return 0;

}

// 구조체 pop, push 이것들은 갈수있는 길들을 push 할때 쓰임 (x,y)// 