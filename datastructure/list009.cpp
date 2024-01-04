#include <stdlib.h>
#include <stdio.h>
// 설계 방안 C 구현 2 : 다중연결리스트 이용
typedef struct Node
{
    char gName;
    char eName;
    Node *nextGroup;
    Node *nextElement;
} Node;
typedef struct Group
{
    Node *header;
    char gName;
} Group;
typedef struct Element
{
    Node *header;
    char eName;
} Element;
Node *getnode()
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->eName = '0';
    newNode->gName = '0';
    return newNode;
}
void initShare(Group *Groups, Element *Elements, int NE, int NG)
{
    for (int i = 0; i < NE; i++)
    {
        Node *H = getnode();
        H->nextGroup = H;
        Elements[i].header = H;
    }
    for (int i = 0; i < NG; i++)
    {
        Node *H = getnode();
        H->nextElement = H;
        Groups[i].header = H;
    }
    return;
}

void traverseShareElements(Group *Groups, int g)
{
    Node *H = Groups[g].header;
    Node *p = H->nextElement;
    while (p != H)
    {
        printf(" elements : %c \n", p->eName);
        p = p->nextElement;
    }
    return;
}

void traverseShareGroups(Element *Elements, int e)
{
    Node *H = Elements[e].header;
    Node *p = H->nextGroup;
    while (p != H)
    {
        printf(" group : %c \n", p->gName);
        p = p->nextGroup;
    }
    return;
}

void addShare(Group *Groups, Element *Elements, int e, int g)
{
    Node *p = getnode();
    Node *HG = Groups[g].header;
    p->nextElement = HG->nextElement;
    HG->nextElement = p;
    Node *HE = Elements[e].header;
    p->nextGroup = HE->nextGroup;
    HE->nextGroup = p;
    p->eName = 'a' + e;
    p->gName = 'A' + g;
    return;
}

int main()
{

    return 0;
}