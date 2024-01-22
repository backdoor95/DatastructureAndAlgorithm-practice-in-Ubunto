#include <bits/stdc++.h>
using namespace std;
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 5; i++)
    {
        v.push_back(i);
    }

    for (int i = 0; i < 5; i++)
    {
        cout << i << "번째 요소 : " << *(v.begin() + i) << "\n";
        cout << &*(v.begin() + i) << endl;
    }
    cout << endl;
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << ' ';
    }

    cout << '\n';

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }

    auto it = v.begin();
    advance(it, 3); // 해당 iterator를 cnt수 만큼 증가
    cout << '\n';
    cout << *it << endl;
    cout << *(v.begin() + 2) << endl;
    // cout << v.begin() << endl;// 이건 에러가 남!! 왜 에러가 나는지는 루키 코드 보면서 알아보면 좋을듯
    return 0;
}