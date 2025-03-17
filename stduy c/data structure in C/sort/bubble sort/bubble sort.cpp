// 버블정렬 (bubble sort) 


/*
버블정렬의 작동 방식

1.n의 크기를 가진 배열을 만든다 

2. 2중 for문을 돌리면서 내가 비교하는 대상이 현제 내가 가지고 있는 값보다 적다면
서로의 위치를 교체한다. 

*/

//////////
///구현///
//////////

// 크기가 n인(1~10000) 일떄의 버블 정렬구현

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning (disable : 4996)
#define SWAP(x,y,t) ((t) = (x),(x) = (y),(y) = (t))
int arr1[10000] = {};


int main()
{

    srand(time(NULL));

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
        int index = i;
        int temp;
        for (int j =i;j<N;j++)
        {
            // 비교하는 대상이 적다면 교체
            if (arr1[i] > arr1[j])
            {
                //위치 교환
                SWAP(arr1[i],arr1[j],temp);
            }
        }

    }
    //출력
    for (int i = 0;i<N;i++)
    {
        printf("%d ",arr1[i]);
    }
}
/*

시간 복잡도 = n^2

- 버블정렬 또한 구현이 쉽고 복잡하지 않지만 시간복잡도가 n^2이기 떄문에 
작은 값을 정렬하지 않는 이상 많은 값이 주어졌을때에서는 잘 사용하지 않는다.

- 안전한 정렬 방식이다. (같은 값들의 위치변환이 없음)

*/
