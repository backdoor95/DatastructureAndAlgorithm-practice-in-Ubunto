#include <bits/stdc++.h>
using namespace std;
int n[26]; // 알파벳 개수는 26개
void print()
{
    for (int i = 0; i < 26; i++)
    {
        cout << n[i] << " ";
    }
    cout << '\n';
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;

    for (auto it = s.begin(); it != s.end(); it++)
    {
        char alphabet = *it;
        n[alphabet - 'a']++;
    }
    print();

    return 0;
}