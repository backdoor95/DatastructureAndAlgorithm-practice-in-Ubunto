#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int y, x, z;
    Point(int y, int x, int z) : y(y), x(x), z(z) {}
    Point()
    {
        y = -1;
        x = -1;
        z = -1;
    }
    bool operator<(const Point &a) const
    {
        if (x == a.x)
        {
            if (y == a.y)
                return z < a.z;
            return y > a.y;
        }
        return x < a.x;
    }
};
struct Point2
{
    int y, x;
};
bool cmp(const Point2 &a, const Point2 &b)
{
    return a.x > b.x;
}
vector<Point2> v;
int main()
{
    for (int i = 0; i < 10; i++)
    {
        v.push_back({10 - i, i});
    }
    sort(v.begin(), v.end(), cmp);

    for (auto it : v)
        cout << it.y << " : " << it.x << endl;
}