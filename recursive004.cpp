#include <stdlib.h>
#include <stdio.h>
#define MAX_SIZE 20
int numbers[20];
int rFindMax(int n)
{
    if (n == 0) return numbers[0];
    int previousMax = rFindMax(n - 1);
    return (previousMax > numbers[n]) ? previousMax : numbers[n];
}
int main()
{

    int n;
    scanf("%d", &n);
    if (n <= 0 || n > MAX_SIZE) {
        printf("Invalid input.\n");
        return 1; // Exit with an error code
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &numbers[i]);
    }

    int max = rFindMax(n - 1);
    printf("%d\n", max);

    return 0;
}