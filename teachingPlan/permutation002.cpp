#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[] = {1, 3, 2};
    cout << "정렬되어 있지 않은 배열기반" << endl;
    do
    {
        for (int i : a)
            cout << i << " ";
        cout << '\n';
    } while (next_permutation(a, a + 3));
    cout << "정렬된 배열기반\n";
    int b[] = {1, 2, 3};
    do
    {
        for (int i : b)
            cout << i << " ";
        cout << '\n';
    } while (next_permutation(b, b + 3));

    /// 밑에는 전부 같은 의미이다.
    do
    {
        for (int i : a)
            cout << i << " ";
        cout << '\n';
    } while (next_permutation(&a[0], &a[3]));

    do
    {
        for (int i : a)
            cout << i << " ";
        cout << '\n';
    } while (next_permutation(&a[0], &a[0] + 3));

    bool flag = 1;
    do
    {
        flag = next_permutation(a, a + 3);
        cout << "flag " << flag << "\n";
        for (int i : a)
            cout << i << " ";
        cout << "\n";
    } while (flag);
    // next_permutation은 새로운 순열이 이전 순열보다 사전순으로 큰 경우 true를 반환.
    
}