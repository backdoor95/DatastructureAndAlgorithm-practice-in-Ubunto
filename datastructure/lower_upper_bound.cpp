#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> a{1, 2, 3, 3, 3, 4};
    cout << lower_bound(a.begin(), a.end(), 3) - a.begin() << "\n";
    cout << upper_bound(a.begin(), a.end(), 3) - a.begin() << "\n";
    // 이터레이터가 어떤 주소를 가지는지 확인하는법
    // ==> &*

    // 해당 요소가 없으면 근방지점을 반환
    vector<int> v;
    for (int i = 2; i <= 5; i++)
        v.push_back(i);
    v.push_back(7);
    
    cout << upper_bound(v.begin(), v.end(), 6) - v.begin() << endl;
    cout << lower_bound(v.begin(), v.end(), 6) - v.begin() << endl;

    

    return 0;
}