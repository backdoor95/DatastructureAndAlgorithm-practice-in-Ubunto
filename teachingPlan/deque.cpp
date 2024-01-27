#include <bits/stdc++.h>
using namespace std;
int main()
{
    // deque는 앞 뒤로 삽입 삭제 가능
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    deque<int> dq;
    dq.push_front(1);
    dq.push_back(2);
    dq.push_back(3);
    cout << dq.front() << endl;
    cout << dq.back() << endl;
    cout << dq.size() << endl;
    dq.pop_back();
    dq.pop_front();
    cout << dq.size() << endl;
}