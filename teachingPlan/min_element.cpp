#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int a = *min_element(v.begin(), v.end());
    auto b = min_element(v.begin(), v.end());
    cout << a << endl;
    cout << (int)(b - v.begin()) << "\n";// 해당 최소값의 인덱스

}