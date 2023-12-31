#include<stdio.h>
void hanoi(int n);
void rHanoi(int n, char from, char mid, char to);
int main(){

    hanoi(3);

    return 0;
}
void hanoi(int n){
    rHanoi(n, 'A', 'B', 'C');
    return;
}
void rHanoi(int n, char from, char aux, char to){

    if(n==1){
        printf("%c => %c\n", from, to);
        return;
    }
    rHanoi(n-1, from, to, aux);
    printf("%c => %c\n", from, to);
    rHanoi(n-1, aux, from, to);
    return;
}