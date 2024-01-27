#include <bits/stdc++.h>
using namespace std;
struct Ralo
{
    int a, b;
    double c, d, e;
};
void print(Ralo ralo)
{
    cout << ralo.a << " " << ralo.b << " " << ralo.c << " " << ralo.d << " " << ralo.e << endl;
}
int main()
{
    Ralo ralo = {1, 1, 1, 1, 1};
    print(ralo);
    vector<Ralo> ret;
    ret.push_back({1, 2, 3, 4, 5});
    ret.push_back({10, 20, 30, 40, 50});
    ret.push_back({});
    ret.push_back({1, 3, 5});
    ret.push_back({2, 4});

    for (Ralo ralo : ret)
    {
        print(ralo);
    }

    // 값을 집어 넣지 않은 경우 0으로 초기화됨
    // char or string 으로 선언한 경우 값을 집어넣지 않게 되면 빈 문자열이 들어감.

    /* output
1 1 1 1 1
1 2 3 4 5
10 20 30 40 50
0 0 0 0 0
1 3 5 0 0
2 4 0 0 0

    */
}