#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a = "love is";
    a += " pain!";
    a.pop_back();
    cout << a << " : " << a.size() << endl;
    cout << char(*a.begin()) << endl;
    /// cout << char(*a.end() - 1) << endl;   // 이렇게 하면 안됨.
    cout << char(*(a.end() - 1)) << endl; // 이렇게 해야함.

    cout << endl
         << endl;

    a.insert(0, "test ");
    cout << a <<" : "<< a.size() << endl;

    a.erase(0, 5);
    cout << a <<" : "<< a.size() << endl;
    auto it = a.find("love");

    if (it != string::npos)
    {
        cout << "해당 문자열을 찾음!" << endl;
    }
    cout << it << endl;
    cout << string::npos << endl;
    cout << a.substr(5, 2) << endl;
    return 0;
}