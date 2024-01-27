#include<bits/stdc++.h>
using namespace std;
stack<string> stk;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stk.push("소");
    stk.push("프");
    stk.push("웨");
    stk.push("어");
    stk.push("학");
    stk.push("과");
    stk.push("문");
    stk.push("준");
    stk.push("호");

    while(stk.size())
    {
        cout<<stk.top()<<"\n";
        stk.pop();
    }
    

}