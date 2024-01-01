#include <stdio.h>
#include <stdlib.h>
// 설계 B 구현 2:연결리스트의 배열 이용
typedef struct Node
{
    Node *prev;
    Node *next;
    char elem;
} node;
typedef struct Group
{
    node *H;
    node *T;
} group;
node *getnode()
{
    node *newNode = (node *)malloc(sizeof(node));
    return newNode;
}

group** initGroup(int M)
{
    group** ppg;
    

    return ppg;
}
int main()
{

    return 0;
}
