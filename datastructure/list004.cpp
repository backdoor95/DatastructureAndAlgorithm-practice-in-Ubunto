#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 100

// 설계 방안 A : 레코드의 리스트 사용
typedef struct Record
{
    char elem;
    char group;
} RECORD;

typedef struct List
{
    int n;
    int N = ARRAY_SIZE;
    RECORD V[ARRAY_SIZE];
} LIST;

RECORD *initGroup(LIST *list)
{
    list->n = 0;
    return list->V;
}

void traverseGroup(LIST *list, char g)
{
    int n = list->n;
    for (int i = 0; i < n; i++)
    {
        if (list->V[i].group == g)
            printf("%c", list->V[i].elem);
    }
    return;
}

void removeGroup(LIST *list, char g)
{
    int i = 0;
    int n = list->n;
    while (i < n)
    {
        if (list->V[i].group == g)
        {   // remove
            list->V[i].elem = '0';
        }
        else
        {
            i = i + 1;
        }
    }
    return;
}
int main()
{
    // 리스트의 확장 : Group and Share

    return 0;
}