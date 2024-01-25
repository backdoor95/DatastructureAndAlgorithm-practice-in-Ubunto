#include <bits/stdc++.h>
using namespace std;
int b[5];
vector<int> a;
// first 내림차순, second 오름차순 정렬하고 싶을때
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first>b.first;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // sort는 재열 등 컨테이너들의 요소를 정렬하는 함수 => 보통 array나 vector를 정렬할 때 쓰임.
    // sort : O(nlogn)의 시간복잡도
    // sort(first, last, *커스텀비교함수)

    /*
    sort()의 세번째 매개변수, 커스텀비교함수를 넣지 않으면 기본적으로 오름차순이며 이를
    커스텀비교함수에 greater<타입>()를 넣어 내림차순으로 변경할 수 있습니다. 참고로
    less<타입>()을 통해 오름차순으로 정렬할 수도 있습니다.
    */

    for (int i = 5; i >= 1; i--)
        b[i - 1] = i;
    for (int i = 5; i >= 1; i--)
        a.push_back(i);
    // 오름차순
    sort(b, b + 5);
    sort(a.begin(), a.end());
    for (int i : b)
        cout << i << ' ';
    cout << '\n';
    for (int i : a)
        cout << i << ' ';
    cout << '\n';

    sort(b, b + 5, less<int>());
    sort(a.begin(), a.end(), less<int>());
    for (int i : b)
        cout << i << ' ';
    cout << '\n';
    for (int i : a)
        cout << i << ' ';
    cout << '\n';

    // 내림차순
    sort(b, b + 5, greater<int>());
    sort(a.begin(), a.end(), greater<int>());
    for (int i : b)
        cout << i << ' ';
    cout << '\n';
    for (int i : a)
        cout << i << ' ';
    cout << '\n';

    vector<pair<int, int>> pv;

    for (int i = 10; i >= 1; i--)
    {
        pv.push_back({i, 10 - i});
    }

    // vector의 경우 따로 설정해주지 않으면 first, second 순으로 오름차순 정렬됨.
    sort(pv.begin(), pv.end());

    for (auto it : pv)
    {
        cout << it.first << " : " << it.second << "\n";
    }
}