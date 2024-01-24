#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int v[3] = {1, 2, 3};
    int ret[3];
    memcpy(ret, v, sizeof(v)); // 깊은 복사이다!!

    cout << ret[1] << endl;
    ret[1] = 100;

    for (int i = 0; i < 3; i++)
        cout << "ret = " << ret[i] << ", v = " << v[i] << endl;

    // 그러나 vector에서는 깊은 복사가 되지 않는다.!!!!
    // trivially Copyable 인 타입이 아닌 경우 함수 자체가 제대로 동작하지 않는다.!!
    if (is_trivial<vector<int>>())
        cout << "this is triviallyCopyable!\n";

    vector<int> v2{1, 2, 3};
    vector<int> ret2(3);
    memcpy(&ret2, &v2, 3 * sizeof(int));
    cout << ret2[1] << "\n";
    ret2[1] = 100;
    cout << ret2[1] << "\n";
    cout << v2[1] << "\n";

    return 0;
}