#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a = "김호노";
    cout << a[0] << endl;
    cout << a[0] << a[1] << a[2] << endl;
    string b = "abc";
    cout << b[0] << endl;
    // 한글은 3바이트 , 영어는 1바이트
    // 그래서 출력할때 이상하게 출력이 된다.
    
    
    return 0;
}