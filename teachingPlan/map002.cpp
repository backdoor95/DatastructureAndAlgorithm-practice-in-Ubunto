#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
map<string, string> mp2;
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // map에서 참조( []  )만 해도 자동으로 맵의 요소가 추가된다.
    // map에 해당 키에 해당하는 요소가 없다면 int는 0 또는 string은 빈문자열로 초기화가 되어 할당됨.

    cout << mp[1] << endl;
    cout << mp2["aaaa"] << endl;

    for (auto i : mp)
        cout << i.first << " " << i.second;
    cout << endl;
    for (auto i : mp2)
        cout << i.first << " " << i.second;
    cout << endl;

    if (mp[1] == 0)
        mp[1] = 20000;

    for (auto i : mp)
        cout << i.first << " " << i.second << endl;

    if (mp.find(5) == mp.end())
        mp[5] = 5000;

    for (auto i : mp)
        cout << i.first << " " << i.second << endl;

}