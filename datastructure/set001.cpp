#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 구조체는 변수만 아니라 함수도 넣을수 있다.
struct student
{
    int id;
    char name[10];
    int year;
    int month;
    int day;

    void init()
    {
        id = 10;
        strcpy(name, "jhMun");
        year = 2023;
        month = 10;
        day = 24;
    }

    void print()
    {
        printf("id = %d \n", id);
        printf("year = %d\n", year);
        printf("month = %d\n", month);
        printf("day = %d\n", day);
    }
};

int main(){

    struct student A;
    A.init();
    A.print();