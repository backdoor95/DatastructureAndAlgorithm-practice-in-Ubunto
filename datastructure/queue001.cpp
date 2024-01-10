#include <stdio.h>
#include <stdlib.h>

struct Que
{
    int f;
    int r;
    int *Q; // 원형 배열
};

int isEmpty(Que *q, int N)
{
    return ((q->r + 1) % N == 0);
}

int isFull(Que *q, int N)
{
    return ((q->r + 2) % N == q->f);
}

void initQue(Que *q, int N)
{
    q->Q = (int *)malloc(sizeof(int)*N);

    for (int i = 0; i < N; i++)
    {
        q->Q[i] = 0;
    }
    

    q->f = 1;
    q->r = 0;
}

void fullQueueException()
{
    printf("FullQueueException : overflow\n");
}

void enqueue(Que *q, int N, int e)
{
    if (isEmpty(q, N))
    {
        fullQueueException();
        printf(">> %d\n", e);
        return;
    }
    q->r = (q->r + 1) % N;
    q->Q[q->r] = e;
}

void emptyQueueException()
{
    printf("EmptyQueueException : underflow\n");
}

int dequeu(Que *q, int N)
{
    if (isEmpty(q, N))
    {
        emptyQueueException();
        return -1;
    }

    int e = q->Q[q->f];
    q->Q[q->f] = 0;
    q->f = (q->f+1)%N;
    return e;
}

void traverse(Que*q, int N)
{
    for (int i = 0; i < N; i++)
    {
        int e = q->Q[i];
        printf("%d ", e);
    }
    printf("\n");
}

int main()
{
    Que q;

    int N = 0;
    int iter = 0;

}