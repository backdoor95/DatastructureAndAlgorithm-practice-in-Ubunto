#include <stdio.h>
#include <stdlib.h>
// 배열로 리스트 구현
typedef struct ArrayList
{
    int *V; // 포인터로 만든이유 : 초기화할때 N의 크기에 따라서 배열의 크기를 조절하기 위해
    int N;
    int n; // 배열안에 들어있는 data의 개수
} ArrayList;
ArrayList initialize(ArrayList arrayList) // pointer 미사용
{
    int arrayListSize = 100;
    arrayList.n = 0;
    arrayList.N = arrayListSize;
    arrayList.V = (int *)malloc(sizeof(int) * arrayListSize);
    return arrayList;
}

ArrayList *initialize2(ArrayList *arrayList) // pointer 사용
{
    int arrayListSize = 200;
    arrayList = (ArrayList *)malloc(sizeof(ArrayList));
    arrayList->n = 0;
    arrayList->N = arrayListSize;
    arrayList->V = (int *)malloc(sizeof(int) * arrayListSize);
    return arrayList;
}

ArrayList *initialize3() // pointer 사용
{
    int arrayListSize = 300;
    ArrayList *arrayList = (ArrayList *)malloc(sizeof(ArrayList));
    arrayList->n = 0;
    arrayList->N = arrayListSize;
    arrayList->V = (int *)malloc(sizeof(int) * arrayListSize);
    return arrayList;
}

void initialize4(ArrayList **arrayList) // pointer 사용
{
    *arrayList = (ArrayList *)malloc(sizeof(ArrayList));
    int arrayListSize = 400;
    (*arrayList)->N = arrayListSize;
    (*arrayList)->n = 0;
    (*arrayList)->V = (int *)malloc(sizeof(int) * arrayListSize);
}

void initialize5(ArrayList *arrayList) // pointer 사용
{
    // int arrayListSize = 500;
    // (*arrayList).N= arrayListSize;
    // (*arrayList).n=0;
    // (*arrayList).V = (int*)malloc(sizeof(int)*arrayListSize);

    int arrayListSize = 500;
    arrayList->n = 0;
    arrayList->N = arrayListSize;
    arrayList->V = (int *)malloc(sizeof(int) * arrayListSize);
}

void traverse(ArrayList *arrayList)
{
    int n = arrayList->n;
    int N = arrayList->N;
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arrayList[i]);
    }
    printf("\n");
    return;
}

void add(ArrayList *arrayList, int r, char e)
{
    int n = arrayList->n;
    int N = arrayList->N;
    if (n == N)
    {
        printf("fullListException\n");
        return;
    }
    if ((r < 0) || (r > n))
    {
        printf("invalidRankException\n");
        return;
    }

    for (int i = n - 1; i >= r; i--)
    {
        arrayList->V[i + 1] = arrayList->V[i];
    }

    arrayList->V[r] = e;
    arrayList->n = arrayList->n + 1;
    return;
}

//data의 자료형에 따라서 반환형이 달라진다.
int remove(ArrayList *arrayList, int r)
{
    int n = arrayList->n;
    int N = arrayList->N;
    if ((r < 0) || (r > n - 1))
    {

        printf("invalidRankException\n");
        return;
    }
    int e =arrayList->V[r];
    for (int i = r+1; i <= n-1; i++)
    {
        arrayList->V[i-1]=arrayList->V[i];
    }
    arrayList->n = arrayList->n - 1;
    return e;
    
}

int main()
{
    ArrayList al;
    ArrayList *al2;
    ArrayList *al3;
    ArrayList *al4;
    ArrayList al5;

    initialize(al);
    printf("n1 = %d, N1 = %d\n", al.n, al.N);

    al2 = initialize2(al2);
    printf("n2 = %d, N2 = %d\n", al2->n, al2->N);

    al3 = initialize3();
    printf("n3 = %d, N3 = %d\n", al3->n, al3->N);

    initialize4(&al4);
    printf("n4 = %d, N4 = %d\n", al4->n, al4->N);

    initialize5(&al5);
    printf("n5 = %d, N5 = %d\n", al5.n, al5.N);

    return 0;
}