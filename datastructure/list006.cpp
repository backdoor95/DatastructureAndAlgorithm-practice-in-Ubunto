#include <stdio.h>
#include <stdlib.h>
// 설계 방안 A의 구현 2 : 연결리스트 이용
typedef struct Node
{
    char elem;
    char group;
    Node *prev;
    Node *next;
} Node;
typedef struct List
{
    Node *H;
    Node *T;
    int n;
} List;
Node *getNode()
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->elem = '0';
    p->group = '0';
    p->next = NULL;
    p->prev = NULL;
    return p;
}
List *initGroup()
{
    List *list = (List *)malloc(sizeof(List));
    list->H = getNode();
    list->T = getNode();
    list->n = 1000;
    return list;
}
List *initGroup2()
{
    Node *H = getNode();
    Node *T = getNode();
    H->next = T;
    T->prev = H;

    List *list = (List *)malloc(sizeof(List)); // 메모리 할당
    // 할당없이 하면 이상한값이 출력됨.
    list->H = H;
    list->T = T;
    list->n = 2000;
    return list;
}
// 순회
void traverseGroup(List *list, char g)
{
    Node *p = list->H;
    while (p != list->T)
    {
        if (p->group == g)
        {
            printf("%c", p->elem);
        }
        p = p->next;
    }
    printf("\n");
    return;
}
int main()
{
    List *list1 = initGroup();

    List *list2 = initGroup2();

    printf("list1 test = %d\n", list1->n);
    printf("list1 H = %p | list1 T = %p\n", list1->H, list1->T);
    printf("list1 H.next = %p | list1 T.prev = %p\n", list1->H->next, list1->T->prev);
    printf("list2 test = %d\n", list2->n);
    printf("list2 H = %p | list2 T = %p\n", list2->H, list2->T);
    printf("list2 H.next = %p | list2 T.prev = %p\n", list2->H->next, list2->T->prev);
    return 0;
}