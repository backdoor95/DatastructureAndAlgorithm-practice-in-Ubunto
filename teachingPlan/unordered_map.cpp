#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> umap;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    umap["aaa"] = 1;
    umap["asdf"] = 2;
    umap["dddccx"] = 3;

    for (auto it : umap)
    {
        cout << it.first << " : " << it.second << "\n";
    }
}