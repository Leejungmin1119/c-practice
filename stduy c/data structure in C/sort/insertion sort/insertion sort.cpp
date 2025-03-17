// 삽입정렬 (insertion sort) 

/*
삽입정렬의 작동 방식

1.n의 크기를 가진 배열을 만든다 

2. 두번째 index를 키값으로 지정, 비교하는 대상이 키값보다 크면 
비교하는 대상을 오른쪽으로 이동시키고 다음 인덱스와 비교

3. key값보다 더적은 값이 나오거나 또는 비교 인덱스가 0 미만이 될때까지
비교

3. 비교가 끝난뒤 key값을 저장

*/

//////////
///구현///
//////////

// 크기가 n인(1~10000) 일떄의 삽입 정렬구현

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning (disable : 4996)

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
    for (int i = 1;i<N;i++)
    {
        int index = arr1[i];
        int j  = i-1;

        // 인덱스 error 및 비교대상이 더 큰지 확인
        while ((j >= 0) && (arr1[j] > index))
        {
            // 비교대상을 j+1칸 위치에 삽입
            arr1[j+1] = arr1[j];
            j--;
        }

        // 최종 key 삽입
        arr1[j+1] = index;

    }
    //출력
    for (int i = 0;i<N;i++)
    {
        printf("%d ",arr1[i]);
    }
}
/*

시간 복잡도 = O(n^2) (최악) /O(n) (최고)

- 최고의 경우 O(n) 최악의 경우 O(n^2)

- 덜 복잡하지만 느리다 (삽입되어야 하는 위치가 멀면 그만큼 많이 이동해야 함)

- 버블정렬, 선택정렬보단 빠름

*/
