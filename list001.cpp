#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    struct Node *prev;
    struct Node *next;
    char elem;
} Node;
typedef struct List
{
    Node *Head;
    Node *Tail;
    int n;
} List;
List *initialize();
Node *getNode();
char get(List *list, int r);
char set(List *list, int r, char e);
void traverse(List *list);
void add(List *list, int r, char e);
void addNodeBefore(Node *p, char e);
char Remove(List *list, int r);
char removeNode(List *list, Node *p);

int main()
{
    List *list = initialize();

    int n, r;
    char menu, e;

    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++)
    {
        scanf("%c", &menu);

        switch (menu)
        {
        case 'A':
            scanf(" %d %c", &r, &e);
            add(list, r, e);
            break;
        case 'G':
            scanf(" %d", &r);
            get(list, r);
            break;
        case 'P':
            traverse(list);
            break;
        case 'D':
            scanf(" %d",&r);
            Remove(list, r);
            break;
        default:
            break;
        }
        getchar();
    }

    return 0;
}
char get(List *list, int r)
{
    if ((r < 1) || (r > list->n))
        printf("get invalidRankException!");
    Node *p = list->Head;
    for (int i = 0; i < r; i++)
    {
        p = p->next;
    }
    return p->elem;
}
char set(List *list, int r, char e)
{
    if ((r < 1) || (r > list->n))
        printf("set invalidRankException!");
    Node *p = list->Head;
    for (int i = 0; i < r; i++)
    {
        p = p->next;
    }
    p->elem = e;
    return e;
}
Node *getNode()
{
    Node *node = (Node *)malloc(sizeof(Node));
    return node;
}
List *initialize()
{
    List *list = (List *)malloc(sizeof(List));
    list->Head = getNode();
    list->Tail = getNode();
    list->Head->next = list->Tail;
    list->Tail->prev = list->Head;
    list->n = 0;
    return list;
}
void traverse(List *list)
{
    Node *p = list->Head->next;
    while (p != list->Tail)
    {
        printf("%c", p->elem);
        p = p->next;
    }
    printf("\n");
    return;
}
void add(List *list, int r, char e)
{
    if ((r < 1) || (r > list->n+1))
        printf("add invalidRankException!");
    Node *p = list->Head;
    for (int i = 0; i < r; i++)
    {
        p = p->next;
    }
    addNodeBefore(p, e);
    list->n = list->n + 1;
    return;
}
void addNodeBefore(Node *p, char e)
{
    Node *q = getNode();
    q->elem = e;
    q->prev = p->prev;
    p->next = p;
    (p->prev)->next = q;
    p->prev = q;
    return;
}
char Remove(List *list, int r)
{
    if ((r < 1) || (r > list->n))
        printf("remove invalidRankException!");
    Node *p = list->Head;
    for (int i = 0; i < r; i++)
    {
        p = p->next;
    }
    char e = removeNode(list, p);
    return e;
}
char removeNode(List *list, Node *p)
{
    char e = p->elem;
    (p->prev)->next = p->next;
    (p->next)->prev = p->prev;
    free(p); // putnode
    return e;
}
