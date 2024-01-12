#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int elem;
    struct node *next;
} node;

typedef struct stack
{
    struct node *top;
} stack;

void initStack(stack *s)
{
    s->top = NULL;
    return;
}

struct node *getNode()
{
    node *p = (node *)malloc(sizeof(node) * 1);
    p->elem = -1;
    p->next = NULL;
    return p;
}

void push(stack *s, int e)
{
    node *p = getNode();
    p->elem = e;
    p->next = s->top;
    s->top = p;
    return;
}

int isEmpty(stack *s)
{
    return s->top == NULL;
}

void emptyStackException()
{
    printf("Stackexception\n");
}

void putnode(node *p)
{
    free(p);
    p = NULL;
}

int pop(stack *s)
{
    if (isEmpty(s))
    {
        emptyStackException();
        return -1;
    }

    int e = s->top->elem;
    node *p = s->top;
    s->top = s->top->next;
    putnode(p);
    return e;
}

void visit(int e)
{
    printf("%c ", e);
}

void traverse(stack *s)
{
    node *p = s->top;
    while (p != NULL)
    {
        visit(p->elem);
        p = p->next;
    }
    printf("\n");
}

int isOperand(char c)
{
    if ('A' <= c && c <= 'Z') // 이 코드로 하면 휠씬 간편
        return 1;
    return 0; //  연산자(operator)일때
}

int strfind(char *str, char s)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == s)
            return i;
    }

    return 0;
}

int getPrior(char s)
{
    char Prior[12] = {'(', '|', '&', '<', '>', '+', '-', '/', '*', '!', '$', '@'}; // unary + (&), unary -(@)
    char Prior_N[12] = {0, 1, 2, 3, 3, 4, 4, 5, 5, 6, 6, 6};
    return Prior_N[strfind(Prior, s)];
}
char top(stack *s)
{
    if (s->top == NULL)
    {
        emptyStackException();
        return 'e';
    }
    return s->top->elem;
}

void write(char c)
{
    if (c == '$')
        printf("+");
    else if (c == '@')
        printf("-");
    else
        printf("%c", c);
}

// 단항 연산자 (+)  , (-)를    $ , @로 변환하기
void checkUnaryOperator(char *infix_array)
{
    int N = strlen(infix_array);
    int idx = 0;

    if (infix_array[0] == '+' || infix_array[0] == '-')
    {
        infix_array[0] = (infix_array[0] == '+') ? '$' : '@';
    }

    for (int i = 1; i < N; i++)
    {
        if (infix_array[i - 1] == ')')
            continue;

        if ((!isOperand(infix_array[i - 1])) && (infix_array[i] == '+' || infix_array[i] == '-'))
            infix_array[i] = (infix_array[i] == '+') ? '$' : '@';
    }
}

void convert(char *infix_array)
{
    stack S;
    initStack(&S);

    checkUnaryOperator(infix_array);

    int N = strlen(infix_array);
    int idx = 0;
    while (idx != N)
    {
        char s = infix_array[idx++];

        if (isOperand(s)) // 피연산자 처리 구문
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
                write(pop(&S));
            pop(&S); // '(' 지우기기
        }
        else
        { // 연산자
            while (!isEmpty(&S) && (getPrior(s) <= getPrior(top(&S))))
                write(pop(&S));

            if (s == '&' || s == '|')
            {
                push(&S, s);
                push(&S, s);
                idx++;
            }
            else
            {
                push(&S, s);
            }
        }
    }

    while (!isEmpty(&S))
        write(pop(&S));
    return;
}

int main()
{
    int n; // 수식의 개수
    char s[101];

    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        scanf("%s", s);
        getchar();
        convert(s);
        printf("\n");
    }
    return 0;
}