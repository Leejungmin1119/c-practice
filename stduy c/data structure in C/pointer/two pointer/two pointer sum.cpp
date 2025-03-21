// 투 포인터 알고리즘(특정한 값 찾기) (two pointer(sum))

/*

투 포인터란? 

두 개의 포인터를 이용하여, 특정 조건을 만족하는 부분 구간 및 부분 값을
구하는 알고리즘 기법


투포인터의 특정한 값찾기

- 두개의 포인터를 이용해서 두개의 합이 특정한 값이 되는 인덱스를 찾는 방식이다.
포인터를 선언할때 각 양쪽 끝에 선언하도록 한다.

1.배열입력, 포인터를 이용하기 전 정렬하기.

2.start 와 end 두개의 포인터 선언하여 양쪽 시작점과 끝점에 배치.

3.만약 start+end값이 많으면 end-- 적으면 start++ 

4. 특정한 값을 찾을때 까지 또는 배열을 다 돌때까지 반복하기.

*/

// 투포인터(특정한 값 찾기) 알고리즘 구현
// glod 5 용액 문제(백준 알고리즘)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning (disable : 4996)


void find_value(int *start,int *end,int arr[])
{
    int value1 = 1000000001,value2 =1000000001;
    int sum =0;
    while(start < end)
    {
        sum = *start + *end;
        
        //0일때
        if (sum == 0)
        {
            value1 = *start;
            value2 = *end;
            break;
        }

        if (abs(sum) < abs(value1 + value2))
        {
            value1 = *start;
            value2 = *end;
        }

        //합이 0보다 클때
        else if(sum > 0)
        {
            *end--;
        }
        //합이 0보다 작을때
        else if(sum < 0)
        {
            *start++;
        }
    }

    printf("%d %d",value1,value2);
}

int main()
{
    int* arr;
    int len;

    scanf("%d",&len);

    //동적 할당
    arr = (int*)malloc(sizeof(int)*len);

    for(int i = 0;i<len;i++)
    {
        scanf("%d",&arr[i]);

    }

    //포인터값 할당
    int *start = &arr[0];
    int *end = &arr[len-1];

    
    find_value(start,end,arr);

    //동적 할당 헤제
    free(arr);

}