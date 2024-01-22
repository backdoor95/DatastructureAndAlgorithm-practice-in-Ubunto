#include <bits/stdc++.h>
using namespace std;
vector<string> split(string input, string delimiter)
{
    vector<string> ret;
    long long pos = 0;
    string token = "";
    // find 함수
    /*
    특정 문자열을 찾아 위치를 반환합니다. 만약 해당 문자열을 못 찾을 경우 string::npos를
    반환하며 O(n)의 시간복잡도를 가집니다
    ex) abcd에서 d를 찾으면 3을 반환
    */
    while ((pos = input.find(delimiter)) != string::npos)
    {
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos + delimiter.length());
    }
    ret.push_back(input);
    return ret;
}
// split 시간초과가 난다면  이 코드 사용하기
// erase를 매번하지 않기 때문에 속도가 더 빠르다.
vector<string> split02(const string &input, string delimiter)
{
    vector<string> result;
    auto start = 0;
    auto end = input.find(delimiter);
    while (end != string::npos)
    {
        result.push_back(input.substr(start, end - start));
        start = end + delimiter.size();
        end = input.find(delimiter, start);
    }
    result.push_back(input.substr(start));
    return result;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s = "안녕하세요 문호는 킹갓제너럴 천재입니다 정말이에요!", d = " ";
    vector<string> a = split(s, d);
    for (string b : a)
    {
        cout << b << "\n";
    }
}