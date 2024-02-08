#include <bits/stdc++.h>
using namespace std;
int a[9];

void printV(vector<int> v)
{
    for (int i : v)
        cout << i << "\n";
}

void combi(int start, vector<int> &b)
{
    if (b.size() == 7)
    {
        int sum = accumulate(b.begin(), b.end(), 0);
        if (sum == 100)
        {
            printV(b);
            exit(0);// 프로세스 종료
        }
    }

    for(int i = start + 1; i< 9;i++)
    {
        b.push_back(a[i]);
        combi(i, b);
        b.pop_back();
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 일곱 난장이

    // 1. 조합이 제일 먼저 생각남. 근데 코드를 못짜겠다.
    //      아마도 9명중에 7명을 선택해서 키의 합이 100이면 출력하면됨

    // 2. 전체 키 합에서 100을 빼면 2명이 스파이 난쟁이의 키의 합이 된다.
    //      그 값이 X라고 한다면 9C2를 했을때 해당 키를 제외하고 sort해서 출력하면된다.

    for (int i = 0; i < 9; i++)
    {
        cin >> a[i];
    }

    sort(a, a + 9);
    vector<int> v;

    combi(-1, v);

    return 0;
}