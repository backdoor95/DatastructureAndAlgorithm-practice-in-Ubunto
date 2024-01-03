#include <stdio.h>
#include <stdlib.h>
// 설계 B 구현 2:연결리스트의 배열 이용
typedef struct Node
{
    struct Node *prev;
    struct Node *next;
    char elem;
} node;
typedef struct Group
{
    node **H;
    node **T;
    int M;
} group;
node *getnode()
{
    node *newNode = (node *)malloc(sizeof(node));
    return newNode;
}

group *initGroup(int M)
{
    group *g = (group *)malloc(sizeof(group));

    g->H = (node **)malloc(M * sizeof(group *));
    g->T = (node **)malloc(M * sizeof(group *));
    g->M = M;

    // -> = (*).

    for (int i = 0; i < M; i++)
    {
        node *h = getnode();
        node *t = getnode();
        h->next = t;
        t->prev = h;
        g->H[i] = h;
        g->T[i] = t;
    }

    return g;
}
// 순회
void traverseGroupu(group *g, int gIdx)
{
    node *p = g->H[gIdx];
    while (p != g->T[gIdx])
    {
        printf("%d\n", p->elem);
        p = p->next;
    }
    return;
}

// 삽입
void addGroupFirst(group *g, int gIndx, char e)
{
    node *newNode = getnode();
    newNode->elem = e;
    g->H[gIndx]->next = newNode;
    g->H[gIndx]->next->prev = newNode;
    newNode->next = g->H[gIndx]->next;
    newNode->prev = g->H[gIndx];
    return;
}

// 삭제
void removeGroup(group *g, int gIdx)
{
    node *p = g->H[gIdx];
    while (p != g->T[gIdx])
    {
        node *pNext = p->next;
        free(p);
        p = pNext;
    }
    g->H[gIdx]->next = g->T[gIdx];
    g->T[gIdx]->prev = g->H[gIdx];
    return;
}

int main()
{
    int M = 10;
    group *pg = initGroup(M);

    return 0;
}
