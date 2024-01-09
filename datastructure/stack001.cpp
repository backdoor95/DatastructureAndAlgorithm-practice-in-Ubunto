#include <stdio.h>
#include <stdlib.h>

struct node
{
    int elem;
    struct node *next;
};
struct stack
{
    struct node *top;
};

void initStack(struct stack *s)
{
    s->top = NULL;
    return;
}

struct node *getNode()
{
    struct node *p = (struct node *)malloc(sizeof(struct node) * 1);
    p->elem = -1;
    p->next = NULL;
    return p;
}

void push(struct stack *s, int e)
{
    struct node *p = getNode();
    p->elem = e;
    p->next = s->top;
    s->top = p;
    return;
}

int isEmpty(struct stack *s)
{
    return s->top == NULL;
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

int pop(struct stack *s)
{
    if (isEmpty(s))
    {
        emptyStackException();
        return -1;
    }

    int e = s->top->elem;
    struct node *p = s->top;
    s->top = s->top->next;
    putnode(p);
    return e;
}

void visit(int e)
{
    printf("%c ", e);
}

void traverse(struct stack *s)
{
    struct node *p = s->top;
    while (p != NULL)
    {
        visit(p->elem);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    struct stack s;
    initStack(&s);

    push(&s, 'C');
    push(&s, 'B');

    push(&s, 'A');

    push(&s, 'X');

    traverse(&s);
    // X A B C 
}