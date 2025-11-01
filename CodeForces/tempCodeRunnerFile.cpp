#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        char first = s[0];
        char last = s[s.length()-1];
        if(s.length() <= 4){
            cout << s << endl;
        }else{
            cout << first + s.length()-2 + last << endl;
        }
    }
}