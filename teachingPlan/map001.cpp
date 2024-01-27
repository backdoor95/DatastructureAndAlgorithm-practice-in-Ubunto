#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
string a[] = {"김씨", "문씨", "최씨"};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 3; i++)
    {
        mp.insert({a[i], i + 1}); // 방법 1. - insert({key, value})
        mp[a[i]] = i + 1;         // 방법 2.
    }

    cout << mp["문씨"] << "\n";

    // 대괄호로 수정 가능하다.
    mp["문씨"] = 1000;

    cout << mp["문씨"] << "\n";
    cout << mp.size() << "\n";

    mp.erase("김씨");
    auto it = mp.find("김씨");

    if (it == mp.end())
        cout << "찾지 못함." << endl;

    it = mp.find("문씨");
    if (it != mp.end())
    {
        cout << (*it).first << " : " << (*it).second << endl;
    }

    for (auto it : mp)
    {
        cout << it.first << " : " << it.second << endl;
    }

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        /* code */
        cout << (*it).first << " : " << (*it).second << endl;
    }

    mp.clear();
}