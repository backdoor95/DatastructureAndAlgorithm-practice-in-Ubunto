#include <bits/stdc++.h>
using namespace std;
void printV(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
int main()
{
    int a[3] = {1, 2, 3};
    vector<int> v;
    for (int i = 0; i < 3; i++)
        v.push_back(a[i]);

    // 1, 2, 3 부터 오름차순으로 순열을 뽑음.
    // next_permutation은  오름차순의 배열을 기반으로 순열을 만들 수 있음.----> 오름차순으로 정렬을 해서 쓰는게 중요.
    do
    {
        printV(v);
    } while (next_permutation(v.begin(), v.end()));

    cout << "---------------" << endl;

    v.clear();
    for (int i = 2; i >= 0; i--)
    {
        v.push_back(a[i]);
    }

    // 3,2,1 부터 내림차순으로 순열을 뽑음
    // prev_permutation은 그와 반대인 내림차순의 배열을 기반으로 순열을 만들 수 있다.
    do
    {
        printV(v);
    } while (prev_permutation(v.begin(), v.end()));

    return 0;
}