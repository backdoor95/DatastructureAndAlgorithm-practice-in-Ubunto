#include <stdio.h>
#include <stdlib.h>

struct node
{
    int elem;
    struct node *next;
};

// 구조체 멤버 변수 / 구조체 멤버 함수
struct stack
{
    struct node *top;
    void initStack()
    {
        top = NULL;
        return;
    }

    struct node *getNode()
    {
        struct node *p = (struct node *)malloc(sizeof(struct node) * 1);
        p->elem = -1;
        p->next = NULL;
        return p;
    }

    void push( int e)
    {
        struct node *p = getNode();
        p->elem = e;
        p->next = top;
        top = p;
        return;
    }

    int isEmpty()
    {
        return top == NULL;
    }

    void emptyStackException()
    {
        printf("Stackexception\n");
    }

    void putnode(struct node *p)
    {
        free(p);
        p = NULL;
    }

    int pop()
    {
        if (isEmpty())
        {
            emptyStackException();
            return -1;
        }

        int e = top->elem;
        struct node *p = top;
        top = top->next;
        putnode(p);
        return e;
    }

    void visit(int e)
    {
        printf("%c ", e);
    }

    void traverse()
    {
        struct node *p = top;
        while (p != NULL)
        {
            visit(p->elem);
            p = p->next;
        }
        printf("\n");
    }
};

int main()
{
    struct stack s;
    s.initStack();

    s.push('C');
    s.push('B');
    s.push('A');
    s.push('X');

    s.traverse();
    // X A B C
}