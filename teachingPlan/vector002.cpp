#include <bits/stdc++.h>
using namespace std;

// 정적할당
vector<int> v1(5, 100); // 5개 요소를 담을수 있는 벡터를 선언, 모든 값을 100으로 채운다.
vector<int> v2{10, 20, 30, 40, 50};

// 2차원 배열
vector<vector<int>> v3;
vector<vector<int>> v4(10, vector<int>(10, 0));
vector<int> v5[10];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int a : v1)
        cout << a << " ";
    cout << endl;
    for (int a : v2)
        cout << a << " ";

    // 2차원 배열
    for (int i = 0; i < 10; i++)
    {
        vector<int> temp;
        v3.push_back(temp);
    }

    return 0;
}