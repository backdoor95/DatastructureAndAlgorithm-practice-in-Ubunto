#include <bits/stdc++.h>
using namespace std;
int a[9];

void printV(vector<int> v)
{
    for (int i : v)
        cout << i << "\n";
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 일곱 난장이

    // 3. 순열을 이용해서 풀 수 있다. 9P7

    for (int i = 0; i < 9; i++)
    {
        cin >> a[i];
    }

    sort(a, a + 9);// next_permutation(a, a+9)를 사용하기 위해서는 sort를 해야함.
    vector<int> v;

    do
    {
        int sum = 0;
        for(int i = 0; i<7; i++) sum += a[i];
        if(sum == 100) break;
    } while (next_permutation(a, a+9));
    
    for(int i=0;i<7;i++)
    cout<<a[i]<<"\n";
    return 0;
}