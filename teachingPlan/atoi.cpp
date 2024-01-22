#include <bits/stdc++.h>
using namespace std;

int a[10], n;
int main()
{
    // atoi : ascii to integer
    string s1 = "100";
    string s2 = "apple";
    string s3 = "iphone";
    // c_str() : string 을 char* 으로 바꿔주는 역할
    cout << atoi(s1.c_str()) << '\n';// 입력받은 문자열이 숫자라면 숫자를 반환
    cout << atoi(s2.c_str()) << '\n';// 입력받은 문자열이 문자라면 0 반환
}