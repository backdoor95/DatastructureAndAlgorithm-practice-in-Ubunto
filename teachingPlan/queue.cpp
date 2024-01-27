#include <bits/stdc++.h>
using namespace std;
queue<int> q;

int main()
{
    for (int i = 0; i < 10; i++)
    {
        q.push(i + 1);
    }

    while (q.size())
    {
        cout << "size : " << q.size() << endl;
        cout << q.front() << "\n"; // 가장 앞에 있는 요소 참조
        q.pop();                   // 가장 앞에 있는 요소를 제거
    }

    cout << endl;

    if (!q.empty())
    {
        cout << q.size() << endl;
        cout << q.front() << endl;
        cout << q.back() << endl;// 이게 출력이 되는 이유는 큐가 비어있을때 접근하면 정의되지 않은 동작이 발생함.
    }
    else
    {
        cout << "queue is empty\n"
             << endl;
    }
}