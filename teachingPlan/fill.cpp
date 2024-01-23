#include <bits/stdc++.h>
using namespace std;
int a[10];
int b[10][10];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(&a[0], &a[10], 100);
    //1차원의 경우 a, a + 10, 즉, 배열의 이름 + 숫자로 가능
    fill(a,a + 10, 100);

    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    fill(&b[0][0], &b[9][10], 10);
    // 2차원 이상일 경우에는 반드시 &b[0][0]+숫자 
    fill(&b[0][0], &b[0][0] + 10 * 10, 2);
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    //fill로 초기화할 경우에는 전체 초기화를 하는게 좋다.
    // 1열 초기화 하고, 2열 초기화 .... n열 초기화가 순차적으로 일어나기 때문.

    return 0;
}