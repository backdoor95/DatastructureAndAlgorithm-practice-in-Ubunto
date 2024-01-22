#include <bits/stdc++.h>
using namespace std;
int main()
{
    // tie를 안쓸경우
    pair<int, int> pi;
    tuple<int, int, int> tl;
    int a, b, c;

    pi = {1, 2};
    a = pi.first;
    b = pi.second;
    cout << a << " : " << b << endl;
    tl = make_tuple(3, 4, 5);
    a = get<0>(tl);
    b = get<1>(tl);
    c = get<2>(tl);
    cout << a << " : " << b << " : " << c << endl;

    return 0;
}