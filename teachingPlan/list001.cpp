#include <bits/stdc++.h>
using namespace std;
list<int> a; // list로 빌드하면 에러발생

void print(list<int> a)
{
    for (auto it : a)
        cout << it << " ";
    cout << endl;
}

int main()
{
    for (int i = 0; i < 3; i++)
    {
        a.push_back(i + 1);
    }

    for (int i = 0; i < 3; i++)
    {
        a.push_front(i + 1);
    }

    auto it = a.begin();
    it++;

    a.insert(it, 1000);
    print(a);

    it = a.begin();
    it++;
    a.erase(it);
    print(a);

    a.pop_front();
    a.pop_back();
    print(a);

    cout << a.front() << " : " << a.back() << endl;
    a.clear();
}