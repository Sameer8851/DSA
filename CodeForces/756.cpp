#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> m;
    if(m % 2 == 0 && m != 2){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}
