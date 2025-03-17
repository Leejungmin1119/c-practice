// 퀵 정렬 (quick sort) 


/*
기본 적인 선택정렬의 작동 방식

1.가장 왼쪽에 있는 값을 피벗으로 삼는다. 

2. 피벗을 기준으로 왼쪽은 피벗 보다 큰값, 오른쪽은 피벗 보다 작은값을 찾아서
그 값들의 위치를 교체한다.

3. 만약 찾았는데 서로 위치가 엇갈릴시 피벗과 가장 작은값의 위치를 바꾸고
그것을 피벗으로 삼는다.

4. 배열을 절반으로 나눈후 이과정을 더이상 나눌 수 없을때 까지 반복한다.

*/

//////////
///구현///
//////////

// 크기가 n인(1~100000) 일떄의 퀵 정렬구현

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning (disable : 4996)
#define SWAP(x,y,z) ((z) = (x),(x) = (y), (y) = (z))
int arr[100000] = {};
int sorted_arr[100000] = {};

//퀵정렬
void Quicksort(int arr[], int left, int right)
{
    if (left<right)
    {
        int pivot = left, left_index = left+1,right_index = right,temp;// 피벗 = 가장 왼쪽, 찾아야 할 인덱스 (왼),오, SWAP을 위한 변수 temp

        while (1)// 반복
        {
            while (left_index <= right && arr[left_index] <= arr[pivot])
                left_index++;

            // 피벗보다 작은 값 찾기
            while (right_index > left && arr[right_index] >= arr[pivot])
                right_index--;

            // 엇갈리면 종료
            if (left_index > right_index)
                break;

            // 찾은 두 값 교환
            SWAP(arr[left_index], arr[right_index], temp);
        }

        // 피벗과 작은 값 교환
        SWAP(arr[pivot], arr[right_index], temp);

        // 재귀 호출
        Quicksort(arr, left, right_index - 1);
        Quicksort(arr, right_index + 1, right);
    }
}

//메인함수
int main()
{

    // 배열의 크기 입력
    int N;
    scanf("%d",&N);

    // 수 입력
    for (int i = 0;i<N;i++)
    {
        // 1이상 100000 이하의 난수 생성
        int number = ((rand()% 10000)+1);

        //저장
        arr[i] = number;
    }

    Quicksort(arr,0,N-1);

    // 출력

    for (int i =0;i<N;i++)
    {
        printf("%d ",arr[i]);
    }
}
/*

- 시간 복잡도 : 평균 : O(nlogn)

- 안정적인 정렬
- 속도가 nlogn 이라 느리지 않고 빠른 편
- 조금 복잡함

*/
