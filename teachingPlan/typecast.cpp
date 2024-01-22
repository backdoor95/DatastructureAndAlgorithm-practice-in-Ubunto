#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    double ret = 2.11134;
    int n = 2;
    int a = (int)round(ret / double(n));
    cout << a << endl;
    // int 는 int끼리
    // double은 double끼리

    vector<int> v1 = {1, 2, 3};
    cout << v1.size() - 10 << endl; // size()는 unsigned int를 반환함.
    cout << (int)v1.size() - 10 << endl;
    /* output
18446744073709551609
-7
*/

    return 0;

}