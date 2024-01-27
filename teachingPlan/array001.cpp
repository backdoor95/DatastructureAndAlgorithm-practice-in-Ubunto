#include <bits/stdc++.h>
using namespace std;

const int mxy = 3;
const int mxx = 4;

int a[mxy][mxx];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < mxy; i++)
    {
        for (int j = 0; j < mxx; j++)
        {
            a[i][j] = (i + j);
        }
    }
}