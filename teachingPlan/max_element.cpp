#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int a = *max_element(v.begin(), v.end()); // max_element는 이터레이터를 반환하기 때문에 *를 붙여서 값을 끄집어낸다.
    auto b = max_element(v.begin(), v.end());

    cout << a << "\n";
    cout << *b << endl;
    cout << b - v.begin() << endl;// 해당 최대값의 인덱스
    cout <<(int)(b - v.begin()) << endl;// 해당 최대값의 인덱스
    //cout << *(b - v.begin()) << endl;//에러 : invalid type argument of unary ‘*’ 
    //cout << b << endl;// 에러 : 이건 연산자 오류가 난다. b가 이터레이터 이기 떄문

    return 0;
}