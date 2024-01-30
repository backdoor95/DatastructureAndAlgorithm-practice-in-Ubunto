#include <bits/stdc++.h>
using namespace std;
int main()
{
    // =========================== 반시계 회전
    vector<int> v = {1, 2, 3, 4, 5, 6};
    rotate(v.begin(), v.begin() + 1, v.end());
    for (int i : v)
        cout << i << ' ';
    // 2 3 4 5 6 1

    vector<int> v1 = {1, 2, 3, 4, 5, 6};
    rotate(v1.begin(), v1.begin() + 2, v1.end());
    for (int i : v1)
        cout << i << ' ';
    // 3 4 5 6 1 2

    vector<int> v2 = {1, 2, 3, 4, 5, 6};
    rotate(v2.begin(), v2.begin() + 2, v2.end());
    for (int i : v2)
        cout << i << ' ';
    // // 1 3 4 5 2 6

    // ============================= 시계 회전
    vector<int> v3 = {1, 2, 3, 4, 5, 6};
    rotate(v3.rbegin(), v3.rbegin() + 1, v3.rend());
    for (int i : v3)
        cout << i << ' ';
    // 6 1 2 3 4 5
    
}
/*
2 3 4 5 6 1 // 반시계
*/