#include<stdio.h>

void inverseArray(int *arr, int LB, int UB){

    int tmp;
    while(LB<=UB){
        tmp = arr[LB];
        arr[LB] = arr[UB];
        arr[UB] = tmp;
        LB++;
        UB--;
    }

}
void printArray(int n, int *arr){
    for (int i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }
    return;
}
int main(){

    int arr[101];
    int n;
    // 뒤집기 정보의 개수
    int inverseCnt;
    // 범위
    int LB, UB;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }


    scanf("%d", &inverseCnt);

    for (int i = 0; i < inverseCnt; i++)
    {
        scanf("%d %d ", &LB, &UB);
        inverseArray(arr, LB, UB);
    }
    
    printArray(n, arr);
    


    return 0;
}