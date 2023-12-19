#include<stdio.h>

void rPrintDigits(int n){
    if(n<10)
        printf("%d\n", n);
    else
        {
            printf("%d\n",n%10);
            rPrintDigits(n/10);
        }

}
int main(){
    int n;
    scanf("%d", &n);

    if(n<0)
        printf("Negative number!");
    else
        rPrintDigits(n);

}