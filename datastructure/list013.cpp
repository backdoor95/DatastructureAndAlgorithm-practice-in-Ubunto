#include <stdlib.h>
#include <stdio.h>
// 응용문제 : 생일 케이크 촛불 끄기
// 해결 : 원형 연결리스트 구현
int N = 10;
typedef struct Node
{
    int elem;
    Node *next;
} Node;
Node *getnode()
{
    Node *p = (Node *)malloc(sizeof(Node));
    return p;
}
Node *buildList(int n)
{
    Node *p = getnode();
    Node *L = p;
    p->elem = 1;
    for (int i = 2; i <= n; i++)
    {
        p->next = getnode();
        p = p->next;
        p->elem = i;
    }
    p->next = L;
    return L;
}
int runSimulation(Node *L, int n, int k)
{
    Node *p = L;
    while (p != p->next)
    {
        for (int i = 1; i < k; i++)
        {
            p = p->next;
        }
        Node *pnext = p->next;
        p->next = (p->next)->next;
        free(pnext);
        p = p->next;
    }
    return p->elem;
}
int candle(int n, int k)
{
    Node *L = buildList(n);
    return runSimulation(L, n, k);
}
int main()
{
    int n = N;
    int k;
    scanf("%d", &k);
    candle(n, k);
    return 0;
    return 0;
}