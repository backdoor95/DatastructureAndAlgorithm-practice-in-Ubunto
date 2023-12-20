#include <stdio.h>
#include <string.h>
char str[101];
int idx;
int len;
char ch;

int rCnt(int i)
{
    if (i < 0)
    {
        return 0;
    }
    if (str[i] == ch)
        return 1 + rCnt(i - 1);
    else
        return rCnt(i - 1);
}
int main()
{

    scanf("%s", str);
    getchar();
    scanf("%c", &ch);

    len = strlen(str);

    printf("%d\n", rCnt(len - 1));

    return 0;
}