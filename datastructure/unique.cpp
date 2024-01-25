#include <bits/stdc++.h>
using namespace std;
vector<int> v;
// unique는 O(n) 시간복잡도를 가진다.
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 5; i++)
    {
        v.push_back(i + 1);
        v.push_back(i + 1);
    }

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << '\n';

    for (int i : v)
    {
        cout << i << " ";
    }
    cout << '\n';

    auto it = unique(v.begin(), v.end());

    cout << *it << endl;
    cout << *(it + 1) << endl;
    cout << *(it + 2) << endl;
    cout << *(it + 3) << endl;

    cout << it - v.begin() << endl;

    for (int i : v)
        cout << i << " ";
    cout << endl;

    v.erase(it, v.end());
    for (int i : v)
        cout << i << " ";
    cout << endl;
    // unique를 사용할때는
    // 1. 먼저 sort를 한다.
    // 2. 그다음 erase하면서 안에서 unique 사용.
    vector<int> s2{4, 3, 3, 5, 1, 2, 3};
    sort(s2.begin(), s2.end());
    s2.erase(unique(s2.begin(), s2.end()), s2.end());
    for (int i : s2)
        cout << i << " ";

    return 0;
}