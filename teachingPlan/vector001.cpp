#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main()
{

    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    for (int a : v)
        cout << a << " ";
    cout << endl;

    v.pop_back();

    for (int a : v)
        cout << a << " ";
    cout << endl;

    v.erase(v.begin(), v.begin() + 3); // 앞에서 3개를 지움
    for (int a : v)
        cout << a << " ";
    cout << endl;

    auto findIter = find(v.begin(), v.end(), 100);
    if (findIter == v.end())
        cout << "not found" << endl;

    fill(v.begin(), v.end(), 10);
    for (int a : v)
        cout << a << " ";
    cout << endl;

    v.clear();
    cout << " all clear \n";
    for (int a : v)
    {
        cout << a << " ";
    }

    cout << endl;
}