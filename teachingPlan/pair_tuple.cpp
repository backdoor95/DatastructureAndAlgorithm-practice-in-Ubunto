#include <bits/stdc++.h>
using namespace std;
pair<int, int> pi;
tuple<int, int, int> tl;
int a, b, c;
int main()
{
    pi = {1, 2};
    // pair의 경우 make_pair(a,b)로 만들수 있다.
    tl = make_tuple(3, 4, 5);
    tie(a, b) = pi;
    cout << a << " : " << b << endl;
    tie(a, b, c) = tl;
    cout << a << " : " << b << " : " << c << endl;
    /* output
1 : 2
3 : 4 : 5
    */
}