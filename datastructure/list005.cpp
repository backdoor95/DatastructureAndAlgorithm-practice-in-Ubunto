#include <stdlib.h>
#include <stdio.h>
typedef struct Node
{
    NODE *prev;
    NODE *next;
    char elem;
    char group;
} NODE;
typedef struct List
{
    NODE *HEAD;
    NODE *TAIL;
    int n;
} LIST;
NODE *getNode()
{
    NODE *node = (NODE *)malloc(sizeof(NODE));
    node->prev = NULL;
    node->next = NULL;
    node->group = NULL;
    node->elem = NULL;
    return node;
}
LIST *initGroup()
{
    LIST *list = (LIST *)malloc(sizeof(LIST));
    list->HEAD = getNode();
    list->TAIL = getNode();
    list->HEAD->next = list->TAIL;
    list->TAIL->prev = list->HEAD;
    list->n = 0;
    return list;
}
void traverseGroup(LIST *list, char g)
{
    NODE *p = list->HEAD->next;
    while (p != list->TAIL)
    {
        if (p->group == g)
            printf("%c", p->elem);
        p = p->next;
    }
    return;
}
void removeNode(NODE* node)
{
    (node->prev)->next = node->next;
    (node->next)->prev = node->prev;
    free(node);
}
void removeGroup(LIST *list, char g)
{
    NODE *p = list->HEAD->next;
    while (p != list->TAIL)
    {
        NODE *pnext = p->next;
        if (p->group == g)
        {
            removeNode(p);
            list->n = list->n - 1;
        }
        p = p->next;
    }
}
int main()
{
    // 설계방안 A 구현 2 : 연결리스트 이용

    return 0;
}