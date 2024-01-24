#include <bits/stdc++.h>
using namespace std;
int n;
const int max_n = 1004;
int a1[max_n];
int a2[max_n][max_n];
int main()
{
    cin >> n;
    int a[n];

    memset(a, 0, sizeof(a));
    for (int i : a)
    {
        cout << i << " ";
    }
    cout << endl;
    // cout << endl;
    // cout << "-----------------------" << endl;
    // memset(c, 0, sizeof(c));
    // for (int i : c)
    // {
    //     cout << i << " ";
    // }

    memset(a1, -1, sizeof(a1));
    memset(a2, 0, sizeof(a2));
    for (int i = 0; i < 10; i++)
        cout << a1[i] << " ";

    /*
    0 또는 -1이란 값으로 초기화할 때는 memset을 쓰는 것이 좋습니다.
    그러나 0, -1 이외의 숫자는 절대 이 memset()으로 초기화 못하니 주의해주세요!
    */

    return 0;
}