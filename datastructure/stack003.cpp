#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// 피연산자는 0~9 한자리 숫자만 입력한다고 가정
// 연산자는 + - x / ( )
int isOperand(char s)
{
    char oper[10]={'0','1,'2','3','4', '5,','6'};
}

void convert(char *infix_array)
{
    struct stack S;
    initStack(&S);

    int N = strlen(infix_array);
    int idx = 0;
    while (idx != N)
    {
        char s = infix_array[idx++];

        if (isOperand(s))
        {
            write(s);
        }
        else if (s == '(')
        {
            push(&S, s);
        }
        else if (s == ')')
        {
            while (top(&S) != '(')
                write(pop(&s));
        }
        else
        { // 연산자
            while( !isEmpty(&S)&&(getPrior(s)<=getPrior(top(&S))))
                write(pop(&S));
            push(&S, s);
        }
    }

    while(!isEmpty(&S))
        write(pop(&S));
    return;
}

int main()
{
    char infix_array[100] = "a-b-c+(d+exf)/g";
    convert(infix_array);
    printf("\n");
}