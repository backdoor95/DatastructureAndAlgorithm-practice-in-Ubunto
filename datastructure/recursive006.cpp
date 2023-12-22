#include<stdio.h>

int gcd(int a, int b){
    if(a==0||b==0)
        return a >= b ? a : b;
    return gcd(b, a%b);
}
int main(){

    int a, b;
    scanf("%d %d", &a, &b);

    int ret = gcd(a, b);

    printf("%d\n", ret);
    return 0;
}