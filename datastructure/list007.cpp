
#include <stdlib.h>
#include <stdio.h>
// 설계 방안 B : 부리스트들의 리스트 사용

// 배열 이용

// M * N  배열을 사용
const int M = 3, N = 8;

int* initGroup(int* n){

    printf(" initGroup 함수에서 배열 n의 주소 = %p, &n = %p\n", n, &n);

    for (int i = 0; i < M; i++)
    {
        n[i]=102;
    }
    return  n;
}
void traverseGroup(int V[][N], int* n, int g)
{
    for (int i = 0; i < n[g]; i++)
    {
        printf("visit V[%d, %d] = %d\n", g, i, V[g][i]);
    }
    
}
int main()
{
    int n[M];
    int v[M][N];
    int g=0;
    printf(" 배열 n의 주소 = %p, &n = %p\n", n, &n);
    initGroup(n);
    for (int i = 0; i < M; i++)
    {
        printf("%d\n", n[i]);
    }

    traverseGroup(v, n, g);
    return 0;
}