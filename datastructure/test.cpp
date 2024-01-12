#include <stdio.h>

#include <stdlib.h>

#include <string.h>

int stackSize, top, sign;

void push(char *stack, char value)
{

    stack[++(top)] = value;
}

char pop(char *stack)
{

    return stack[(top)--];
}

int operand(char *inArray, int i)
{

    if ((top != i) && (i == 0) && ((inArray[i] == '+') || (inArray[i] == '-')))
    {

        sign = 1;

        return 6;
    }

    else if ((top != -1) && ((inArray[i] == '+') || (inArray[i] == '-')) && ((inArray[i - 1] == '|') || (inArray[i - 1] == '&') || (inArray[i - 1] == '<') || (inArray[i - 1] == '>') || (inArray[i - 1] == '-') || (inArray[i - 1] == '+') || (inArray[i - 1] == '*') || (inArray[i - 1] == '/') || (inArray[i - 1] == '!')))
    {

        return 6;
    }

    else if (inArray[i] == '|')
    {

        return 1;
    }

    else if (inArray[i] == '&')
    {

        return 2;
    }

    else if (inArray[i] == '>' || inArray[i] == '<')
    {

        return 3;
    }

    else if (inArray[i] == '+' || inArray[i] == '-')
    {

        return 4;
    }

    else if (inArray[i] == '*' || inArray[i] == '/')
    {

        return 5;
    }

    else if (inArray[i] == '!')
    {

        return 6;
    }

    else
    {

        return 0;
    }
}

int main()
{

    int calculateSize, number;

    char inArray[100], outArray[100], stack[100];

    scanf("%d", &calculateSize);

    getchar();

    for (int i = 0; i < calculateSize; i++)
    {

        number = 0, top = -1, sign = 0;

        for (int j = 0; j < 100; j++)
        {

            outArray[j] = '\0';

            stack[j] = '\0';
        }

        scanf("%s", inArray);

        getchar();

        for (int j = 0; j < strlen(inArray); j++)
        {

            if (inArray[j] == '(')
            {

                push(stack, inArray[j]);
            }

            else if (inArray[j] == ')')
            {

                while (stack[top] != '(')
                {

                    outArray[number++] = pop(stack);
                }

                pop(stack);
            }

            else if (operand(inArray, j) == 6)
            {

                push(stack, inArray[j]);
            }

            else if (operand(inArray, j) == 0)
            {

                outArray[number++] = inArray[j];
            }

            else
            {

                if (sign == 1)
                {

                    outArray[number++] = pop(stack);
                }

                else
                {

                    while ((top != -1) && (operand(inArray, j) <= operand(stack, top)))
                    {

                        outArray[number++] = pop(stack);
                    }
                }

                if ((operand(inArray, j) == 1) || (operand(inArray, j) == 2))
                {

                    push(stack, inArray[j++]);
                }

                push(stack, inArray[j]);
            }
        }

        while (top != -1)
        {

            outArray[number++] = pop(stack);
        }

        printf("%s\n", outArray);
    }
}