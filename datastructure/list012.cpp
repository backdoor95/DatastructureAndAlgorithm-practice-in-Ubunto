#include <stdio.h>
#include <stdlib.h>
// 응용문제 : 생일 케이크 촛불 끄기
// 해결 : 배열
int N = 10;
void buildList(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        A[i] = i + 1;
    }
    return;
}
int runSimulationVer1(int A[], int n, int k)
{
    int r = 0;
    while (n > 1)
    {
        int i = 0;
        while (i < k)
        {
            r = (r + 1) % N;
            if (A[r] != 0)
                i = i + 1;
        }
        A[r] = 0;
        n = n - 1;
        while (A[r] == 0)
        {
            r = (r + 1) % N;
        }
    }
    return A[r];
}
int* remove(int A[], int n, int r)
{
    int *newArr = (int *)malloc(sizeof(int) * n);
    for (int i = 0, j = 0; j < n + 1; i++, j++)
    {
        if (j == r)
        {
            i = i - 1;
            continue;
        }
        newArr[i] = A[j];
    }
    free(A);
    return newArr;
}
int runSimulationVer2(int A[], int n, int k)
{
    int r = 0;
    while (n > 1)
    {
        r = (r + k) % n;
        /// remove candle
        A = remove(A, n - 1, r);
        n = n - 1;
    }
    return A[0];
}
int candle(int A[], int n, int k)
{
    buildList(A, n);
    return runSimulationVer1(A, n, k);
    // return runSimulationVer2(A, n, k);
}
int main()
{
    int n = N;
    int *A = (int *)malloc(sizeof(int) * N);
    int k;
    scanf("%d", &k);
    candle(A, n, k);
    return 0;
}