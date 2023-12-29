
#include <stdlib.h>
#include <stdio.h>
// 설계 방안 B : 부리스트들의 리스트 사용

// 배열 이용

// M * N  배열을 사용
int M = 3, N = 8;

int* initGroup(int* n){

    printf(" initGroup 함수에서 배열 n의 주소 = %p, &n = %p\n", n, &n);

    for (int i = 0; i < M; i++)
    {
        n[i]=102;
    }
    return  n;
}

int main()
{
    int n[M];

    printf(" 배열 n의 주소 = %p, &n = %p\n", n, &n);
    initGroup(n);
    for (int i = 0; i < M; i++)
    {
        printf("%d\n", n[i]);
    }

    return 0;
}