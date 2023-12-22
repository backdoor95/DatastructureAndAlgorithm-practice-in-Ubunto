#include<stdio.h>
int sum(int n){
    int ret;
    return ret=(n*(n+1)/2);
}
int main(){
    int x;
    scanf("%d",&x);

    int mainRet = sum(x);
    printf("%d\n", mainRet);
}