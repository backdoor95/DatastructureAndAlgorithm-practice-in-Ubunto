#include <stdlib.h>
#include <stdio.h>
// deque
struct node
{
    int elem;
    struct node *prev;
    struct node *next;
};

struct deque
{
    struct node *r;
    struct node *f;
};

void initDeque(deque *q)
{
    q->r = NULL;
    q->f = NULL;
}

int isEmpty(deque *q)
{
    return (q->f == NULL);
}

void emptyQueueException()
{
    printf("underflow\n");
}

struct node *getnode()
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->elem = -1;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

void add_front(deque *q, int X)
{
    struct node *p = getnode();
    p->elem = X;
    p->next = NULL;
    p->prev = NULL;
    if (isEmpty(q))
    {
        q->f = p;
        q->r = p;
    }
    else
    {
        p->next = q->f;
        q->f->prev = p;
        q->f = p;
    }
}

void add_rear(deque *q, int X)
{
    struct node *p = getnode();
    p->elem = X;

    if (isEmpty(q))
    {
        p->prev = NULL;
        p->next = NULL;

        q->f = p;
        q->r = p;
    }
    else
    {
        p->prev = q->r;
        q->r->next = p;
        q->r = p;
    }
}

int delete_front(deque* q)
{
    if(isEmpty(q))
    {
        emptyQueueException();
        return -1;
    }

    int e = q->f->elem;
    struct node* p = q->f;
    q->f = q->f->next;

    if(q->f == NULL)
        q->r = NULL;
    else
        q->f->prev = NULL;

    free(p);
    p = NULL;
    return e;
}

int delete_rear(deque* q)
{
    if(isEmpty(q))
    {
        emptyQueueException();
        return -1;
    }

    int e = q->r->elem;
    struct node* p= q->r;
    q->r = q->r->prev;

    if(q->r == NULL)
        q->f = NULL;
    else
        q->r->next = NULL;
    
    free(p);
    p= NULL;
    return e;

}

void traverse(deque* q)
{
    struct node* p = q->f;
    while(p!=NULL)
    {
        printf(" %d", p->elem);
        p= p->next;
    }
    printf("\n");
}

int main()
{

    return 0;
}