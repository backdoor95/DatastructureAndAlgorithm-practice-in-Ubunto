#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<pair<int, int>> v;
    for (int i = 0; i < 5; i++)
    {
        v.push_back({i, i});
    }

    for (auto it : v)
    {
        cout << it.first <<" : "<< it.second << endl;
    }

    for (pair<int, int> it : v)
    {
        cout << it.first <<" : "<< it.second << endl;
    }
}