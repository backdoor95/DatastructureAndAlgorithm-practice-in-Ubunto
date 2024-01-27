#include<bits/stdc++.h>
using namespace std;
multiset<int> ms;
int main()
{
    // multiset은 중복을 허용함.
    for (int i = 5; i >= 1; i--)
    {
        ms.insert(i);
        ms.insert(i);
    }

    for(int it : ms)
    {
        cout<<it<<" ";
    }
    
    return 0;
}