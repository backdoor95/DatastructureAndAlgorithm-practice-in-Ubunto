#include <bits/stdc++.h>
using namespace std;
int main()
{
    // void reverse(first, last);

    string a = "It's hard to have a sore leg";
    reverse(a.begin(), a.end());
    cout << a << endl;
    reverse(a.begin(), a.end());
    cout << a << endl;
    reverse(a.begin(), a.end());
    cout << a << endl;
    reverse(a.begin() + 3, a.end());
    cout << a << endl;

    return 0;
}