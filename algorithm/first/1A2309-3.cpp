#include <bits/stdc++.h>
using namespace std;
pair<int, int> ret;
int a[9], sum;
vector<int> v;
void solve()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (sum - a[i] - a[j] == 100)
            {
                ret = {i, j};
                return;
            }
        }
    }
}
int main()
{
    for (int i = 0; i < 9; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    solve();

    for (int i = 0; i < 9; i++)
    {
        if (ret.first == i || ret.second == i)
            continue;
        v.push_back(a[i]);
    }

    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << "\n";
    }

    return 0;
}