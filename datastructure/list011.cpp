#include <stdio.h>
#include <stdlib.h>
// 다항식
typedef struct Node
{
    int coef; // 항의 계수
    int exp;  // 항의 차수
    struct Node *next;
} Node;
Node *getnode()
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    return newNode;
}
Node *appendTerm(Node *k, int c, int e)
{
    Node *t = getnode();
    t->coef = c;
    t->exp = e;
    t->next = NULL;
    k = t;
    return k;
}
Node *addPoly(Node *x, Node *y)
{
    Node *result = getnode();
    result->next = NULL;
    Node *i = x->next;
    Node *j = y->next;
    Node *k = result;
    while ((i != NULL) && (j != NULL))
    {
        if (i->exp > j->exp)
        {
            k = appendTerm(k, i->coef, i->exp);
            i = i->next;
        }
        else if (i->exp < j->exp)
        {
            k = appendTerm(k, j->coef, j->exp);
            j = j->next;
        }
        else
        {
            int sum = i->coef + j->coef;
            if (sum != 0)
            {
                k = appendTerm(k, sum, i->exp);
            }
            i = i->next;
            j = j->next;
        }
    }
    while(i!=NULL)
    {
        k = appendTerm(k,i->coef, i->exp);
        i = i->next;
    }
    while(j!=NULL)
    {
        k = appendTerm(k, j->coef, j->exp);
        j = j->next;
    }
    return result;
}
Node *subPoly(Node *x, Node *y)
{
    Node *result = getnode();
    result->next = NULL;
    Node *i = x->next;
    Node *j = y->next;
    Node *k = result;
    while ((i != NULL) && (j != NULL))
    {
        if (i->exp > j->exp)
        {
            k = appendTerm(k, i->coef, i->exp);
            i = i->next;
        }
        else if (i->exp < j->exp)
        {
            k = appendTerm(k, -(j->coef), j->exp);
            j = j->next;
        }
        else
        {
            int diff = i->coef - j->coef;
            if (diff != 0)
            {
                k = appendTerm(k, diff, i->exp);
            }
            i = i->next;
            j = j->next;
        }
    }
    while(i!=NULL)
    {
        k = appendTerm(k,i->coef, i->exp);
        i = i->next;
    }
    while(j!=NULL)
    {
        k = appendTerm(k, -(j->coef), j->exp);
        j = j->next;
    }
    return result;
}
int main()
{

    return 0;
}