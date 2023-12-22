#include <stdlib.h>
#include <stdio.h>
// 단일연결리스트
// single linked list
typedef struct Node
{
    char elem;
    Node *next;
} NODE;

typedef struct List
{
    Node *H;
    int n;
} LIST;

LIST *initialize()
{
    LIST *list = (LIST *)malloc(sizeof(LIST));
    list->H = NULL;
    list->n = 0;
    return list;
}

char get(LIST *list, int r)
{
    if ((r < 1) || (r > list->n))
    {
        printf("invalidRankException\n");
        return;
    }
    NODE *p = list->H;
    for (int i = 1; i <= r - 1; i++)
    {
        p = p->next;
    }
    return p->elem;
}

char get(LIST *list, int r, char e)
{
    if ((r < 1) || (r > list->n))
    {
        printf("invalidRankException\n");
        return;
    }
    NODE *p = list->H;
    for (int i = 1; i <= r - 1; i++)
    {
        p = p->next;
    }

    p->elem = e;
    return e;
}

void traverse(LIST *list)
{
    NODE *p = list->H;
    while (p != NULL)
    {
        printf("%c", p->elem);
        p = p->next;
    }
    return;
}

NODE *getnode()
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    return newNode;
}

void addNode(LIST *list, NODE *p, char e)
{
    NODE *q = getnode();
    q->next=NULL;
    q->elem = e;
    if (p == NULL)
    {
        p = q;
        list->H = q;// 헤더에 첫번째 값을 넣어줘야함.
    }
    else
    {
        q->next = p->next;
        p->next = q;
    }
    return;
}

void add(LIST *list, int r, char e)
{
    if ((r < 1) || (r > list->n))
    {
        printf("invalidRankException\n");
        return;
    }
    NODE *p = list->H;
    for (int i = 1; i <= r - 2; i++)
    {
        p = p->next;
    }
    addNode(list, p, e);
    list->n = list->n + 1;
    return;
}

char removeNode(LIST *list, NODE *p)
{
    NODE *q = p->next;
    char e = q->elem;
    p->next = q->next;
    free(q);
    return e;
}

char remove(LIST *list, int r)
{
    if ((r < 1) || (r > list->n))
    {
        printf("invalidRankException\n");
        return;
    }
    NODE *p = list->H;
    for (int i = 1; i <= r - 2; i++)
    {
        p = p->next;
    }
    char e = removeNode(list, p);
    list->n = list->n - 1;
    return e;
}

int main()
{

    return 0;
}