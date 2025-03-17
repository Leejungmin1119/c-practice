// 합병정렬 (merge sort) 


/*
기본 적인 선택정렬의 작동 방식

1.n의 크기를 가진 배열을 n = 1이 될때까지 반으로 나눈다. 

2. 나눈 것들을 합친뒤 정렬을 한다.

3. 다 끝날때 까지 반복한다.

*/

//////////
///구현///
//////////

// 크기가 n인(1~100000) 일떄의 병합 정렬구현

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning (disable : 4996)
int arr[100000] = {};
int sorted_arr[100000] = {};

//다시 합치는 함수수
void merge_sort(int arr[], int left, int right,int mid)
{
    int N = left;
    int index_right = mid+1;
    int index_left = left;
    // 정렬할 배열의 크기
    while((index_left <= mid) && (index_right <= right))
    {
        // 왼쪽 > 오른쪽
        if (arr[index_left] > arr[index_right])
        {
            sorted_arr[N++] = arr[index_right++];
        }
        // 왼쪽 < 오른쪽
        else
        {
            sorted_arr[N++] = arr[index_left++];
        }
    }
    // 나머지 배열도 더하기
    if (index_right <= right)
    {
        for (int i = index_right;i<=right;)
        {
            sorted_arr[N++] = arr[i++];
        }
    }
    else if (index_left <= mid)
    {
        for (int i = index_left;i<=mid;)
        {
            sorted_arr[N++] = arr[i++];
        }
    }

    // 다시 원래 배열에다가 복사하기기
    for (int i = left;i<=right;i++)
    {
        arr[i] = sorted_arr[i];
    }

}

//분할함수
void merge_sort_divice(int arr[],int left,int right)
{
    // 배열을 나눌수 있는지 확인
    if (left < right)
    {
        int mid = (left+right)/2;

        // 분할
        merge_sort_divice(arr,left,mid);
        merge_sort_divice(arr,mid+1,right);
        merge_sort(arr,left,right,mid);

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

    merge_sort_divice(arr,0,N-1);

    // 출력

    for (int i =0;i<N;i++)
    {
        printf("%d ",arr[i]);
    }
}
/*

- 시간 복잡도 : O(nlogn)

- 안정적인 정렬
- 속도가 nlogn 이라 느리지 않고 빠른 편
- 메모리 소모가 좀 큼 (부과적인 메모리 할당 필요)
- 조금 복잡함

*/
