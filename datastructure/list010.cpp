#include <stdlib.h>
#include <stdio.h>
// 응용 문제 : 원형배열

// 변수 N: 배열의 크기
const int N = 10;

// 변수 f
int f; // f = first

// 변수 l
int l; // l = last

char A[N];

int size()
{
    return (N - f + l + 1) % N;
}
char get(int r)
{
    if ((r < 0) || (r >= size()))
    {
        printf("r = %d , size = %d\n", r, size());
        printf("invalidRankException\n");
        exit(1);
    }
    return A[(f + r) % N];
}
char set(int r, char e)
{
    if ((r < 0) || (r >= size()))
    {
        printf("r = %d , size = %d\n", r, size());
        printf("invalidRankException\n");
        exit(1);
    }
    A[(f + r) % N] = e;
    return e;
}
void add(int r, int e)
{
    int n = size();
    if (n == N - 1)
    {
        printf("r = %d , size = %d\n", r, n);
        printf("fullListException\n");
        exit(1);
    }
    if ((r < 0) || (r > size()))
    {
        printf("r = %d , size = %d\n", r, n);
        printf("invalidRankException\n");
        exit(1);
    }
    if (r < n / 2)
    {
        for (int i = 0; i < r; i++)
        {
            A[(f + i - 1) % N] = A[(f + i) % N];
        }
        A[(f + r - 1) % N] = e;
        f = (f - 1) % N;
    }
    else
    {
        for (int i = n - 1; i >= r; i--)
        {
            A[(f + i + 1) % N] = A[(f + i) % N];
        }
        A[(f + r) % N] = e;
        l = (l + 1) % N;
    }
    return;
}
char remove(int r)
{
    int n = size();
    if (n == 0)
    {
        printf("emptyListException\n");
        exit(1);
    }
    if ((r < 0) || (r >= n))
    {
        printf("r = %d , size = %d\n", r, n);
        printf("invalidRankException\n");
        exit(1);
    }
    char e = A[(f + r) % N];
    if (r < n / 2)
    {
        for (int i = r - 1; i >= 0; i--)
        {
            A[(f + i + 1) % N] = A[(f + i) % N];
        }
        f = (f + 1) % N;
    }
    else
    {
        for (int i = r + 1; i < n; i++)
        {
            A[(f + r - 1) % N] = A[(f + i) % N];
        }
        l = (l - 1) % N;
    }
    return e;
}
int main()
{
    int n;
    int r;
    char e, c;
    while (1)
    {
        printf("1. size\n2. get\n3. set\n4. add\n5. remove\n");
        scanf("%d", &n);
        getchar();
        switch (n)
        {
        case 1:
            printf("저장된 문자열의 size는 %d 입니다.\n", size());
            break;
        case 2:
            scanf("%d", &r);
            getchar();
            printf("해당 위치(인덱스 번호 = %d)의 문자는 %c 입니다.\n", r, get(r));
            break;
        case 3:
            scanf("%d %c", &r, &e);
            getchar();
            c = set(r, e); // 변경
            printf("해당 위치(인덱스 번호 = %d)의 문자는 %c 입니다.\n", r, c);
            break;
        case 4:
            scanf("%d %c", &r, &e);
            getchar();
            add(r, e);
            printf("문자 add 성공!\n");
            break;
        case 5:
            scanf("%d", &r);
            getchar();
            c = remove(r);
            printf("문자 %c 제거 완료!\n", c);
            break;
        default:
            printf("프로그램을 종료합니다.\n");
            return 0;
        }
    }

    return 0;
}