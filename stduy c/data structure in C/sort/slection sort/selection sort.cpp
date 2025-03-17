// 선택정렬 (selection sort) 


/*
기본 적인 선택정렬의 작동 방식

1.n의 크기를 가진 배열을 만든다 

2. 가장 작은 값을 찾아 바꿔야 할 인덱스에 있는 값과 바꾼다.

3. n의 크기만큼 반복한다.


*/

//////////
///구현///
//////////

// 크기가 n인(1~10000) 일떄의 선택 정렬구현

#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable : 4996)
#define SWAP(x,y,t) ((t) = (x),(x) = (y),(y) = (t))
int arr1[10000] = {};


int main()
{
    // 배열의 크기 입력
    int N;
    scanf("%d",&N);

    // 수 입력
    for (int i = 0;i<N;i++)
    {
        // 1이상 10000 이하의 난수 생성
        int number = ((rand()% 10000)+1);

        //저장
        arr1[i] = number;
    }

    //탐색
    for (int i = 0;i<N;i++)
    {
        int min = INT_MAX;
        int index = i;
        int temp;
        for (int j =i;j<N;j++)
        {
            //배열의 최솟값 찾기
            if (arr1[j] < min)
            {
                min = arr1[j];
                index = j;
            }
        }

        //위치 교환
        SWAP(arr1[i],arr1[index],temp);



    }
    //출력
    for (int i = 0;i<N;i++)
    {
        printf("%d ",arr1[i]);
    }
}
/*

시간 복잡도 = n^2

- 선택정렬은 구현이 쉽고 복잡하지 않지만 시간복잡도가 n^2이기 떄문에 
작은 값을 정렬하지 않는 이상 많은 값이 주어졌을때에서는 잘 사용하지 않는다.

- 위험하지 않는 정렬에 속한다.

*/
