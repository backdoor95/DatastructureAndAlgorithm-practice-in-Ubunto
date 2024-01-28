#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq; // 오름차순
priority_queue<int> pq2;                           // 내림차순
priority_queue<int, vector<int>, less<int>> pq3;   // 내림차순
struct Point
{
    int y, x;
    Point(int y, int x) : y(y), x(x) {}
    Point()
    {
        y = -1;
        x = -1;
    }
    bool operator<(const Point &a) const
    {
        return x > a.x;
    }
};
struct Point2
{
    int y, x;
};
struct cmp
{
    bool operator()(Point2 a, Point2 b)
    {
        return a.x < b.x;
    }
};
priority_queue<Point> pq4;
priority_queue<Point2, vector<Point2>, cmp> pq5;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 5; i >= 1; i--)
    {
        pq.push(i);
        pq2.push(i);
        pq3.push(i);
    }

    while (pq.size())
    {
        cout << pq.top() << " : " << pq2.top() << " : " << pq3.top() << "\n";
        pq.pop();
        pq2.pop();
        pq3.pop();
    }

    pq4.push({1, 1});
    pq4.push({1, 1});
    pq4.push({1, 1});
    pq4.push({1, 1});
    pq4.push({1, 1});
    pq4.push({1, 1});
    // 우선 순위 큐에서 커스텀 정렬을 넣을 때는 반대라고 생각하기
    // 가장 최소를 끄집어 내고 싶을 때, >
    // 가장 최대를 끄집어 내고 싶을 때, <
}