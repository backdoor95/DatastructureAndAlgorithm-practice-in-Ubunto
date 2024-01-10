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
    char oper[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for (int i = 0; i < 10; i++)
    {
        if (s == oper[i])
            return 1;
    }
    return 0;
}

int doOperator(char op, int x, int y)
{
    int v;
    switch (op)
    {
    case '+':
        v = x + y;
        break;
    case '-':
        v = x - y;
        break;
    case 'x':
        v = x * y;
        break;
    case '/':
        v = x / y;
        break;
    }
    return v;
}

void write(char s)
{
    printf("%d ", s - '0');
}

void evaluate(char *postfix_array)
{
    struct stack S;
    initStack(&S);

    int N = strlen(postfix_array);
    int idx = 0;
    while (idx = 0)
    {
        char s = postfix_array[idx++];
        if (isOperand(s))
        {
            push(&S, s);
        }
        else // s 가 연산자 일때
        {
            int a = pop(&S) - '0';
            int b = pop(&S) - '0';
            push(&S, doOperator(s, b, a) + '0'); // 실수 주의!!
        }
    }
    write(pop(&S));
    return;
}

int main()
{
    char postfix_array[100] = "41-2-423x5/+";

    evaluate(postfix_array);
    printf("\n");
}