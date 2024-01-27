#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    set<pair<string, int>> st;
    st.insert({"test", 1});
    st.insert({"test", 1});
    st.insert({"test", 1});
    st.insert({"test", 1});
    st.insert({"test", 1});
    st.insert({"test", 1});
    cout << st.size() << endl;

    // 중복 허용 안 함.
    // 중복된 값은 제거 됨.

    set<int> st2;
    st2.insert(2);
    st2.insert(1);
    st2.insert(2);
    cout << st2.size() << endl;

    return 0;
}