// 쉘정렬 (shell sort) 


/*
기본 적인 선택정렬의 작동 방식

1.n의 크기를 가진 배열을 만든다 

2. 제일 처음에는 n/2 의 간격을 만든 뒤 그 간격대로 배열을 나눈다

3. 나눠진 애들끼리 따로 삽입정렬을 실행한다.

4. 다시 간격을 1/2 하여 간격이 1이 될때까지 2~3과정을 반복한다.

*/

//////////
///구현///
//////////

// 크기가 n인(1~10000) 일떄의 쉘 정렬구현

#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable : 4996)
int arr1[10000] = {};

// 정렬 함수
void shell_sort(int arr[],int n)
{
    //간격나누기
    for (int gap = n/2;gap>0;gap/=2)
    {

        //간격 나눠서 따로 정렬
        for (int i =gap;i<n;i++)
        {
            int key = arr[i];
            int k =  i;

            //삽입정렬의 기능 이용
            while((k >= gap) && (key < arr[k-gap]))
            {
                arr[k] = arr[k-gap];
                k -=gap;
            }

            arr[k] = key;

        }

    }
    
    //출력
    for (int i = 0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}

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
    shell_sort(arr1,N);
}
/*

- 시간 복잡도 : O(n^2) (최악) O(n^1.5) (평균) 

- 평균적인 정렬이 삽입정렬 보다 빠름(성능면에서 조금더 띄어남)

*/
