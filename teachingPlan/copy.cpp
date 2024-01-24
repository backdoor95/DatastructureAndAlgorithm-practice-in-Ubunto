#include <bits/stdc++.h>
using namespace std;
int main()
{
    // copy는 memcpy()와 똑같은 동작을 하는 함수임.
    // vector, array 모두 사용가능

    vector<int> v{
        1,
        2,
        3,
        4};
    vector<int> ret(4); // 복사하는 벡터와 복사당하는 벡터의 크기를 맞춰줘야한다.
    // 만약에 복사하는 벡터의 크기가 복사당하는 벡터의 크기보다 작을 경우, 복사당하는 벡터를 전부를 copy할 수 없다.
    copy(v.begin(), v.end(), ret.begin());
    cout << ret[1] << endl;
    ret[1] = 100;

    cout << ret[1] << endl;
    cout << v[1] << endl;

    for (auto it : ret)
    {
        cout << it << " ";
    }
    cout << endl;

    cout << "ret end" << endl;

    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;

    cout << "v end" << endl;

    /////////// 배열 array
    int n = 3;// 배열의 크기
    int arr[n] = {1, 2, 3};
    int ret2[n];
    copy(arr, arr + n, ret2);
    cout << ret2[1] << "\n";
    ret2[1] = 100;
    cout << ret2[1] << "\n";
    cout << arr[1] << "\n";
    return 0;
}