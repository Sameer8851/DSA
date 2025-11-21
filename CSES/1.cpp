
#include <bits/stdc++.h>
using namespace std;

void solve(set<string> &arr, int i, string& s)
{
    if (i == s.size())
    {
        arr.insert(s);
        return;
    }
    for (int j = i; j < s.size(); j++)
    {
        swap(s[i], s[j]);
        solve(arr, i + 1, s);
        swap(s[i], s[j]);
    }
}

int main()
{
    string s;
    cin >> s;
    set<string> arr;

    solve(arr, 0, s);
    cout << arr.size() << endl;
    for (auto s : arr)
    {
        cout << s << endl;
    }
}