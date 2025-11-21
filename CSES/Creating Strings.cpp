
#include <bits/stdc++.h>
using namespace std;

void solve(vector<string>& arr,int i,string s){
    if(i == s.size()){
        return ;
    }
    arr.push_back(s);
   for(int idx = i+1;idx < s.length();idx++){
        swap(s[i],s[idx]);
        solve(arr,idx,s);
        swap(s[i],s[idx]);
   }
    
}

int main(){
    string s;
    cin >> s;
    vector<string> arr;
    
    solve(arr,0,s);
    cout << arr.size() << endl;
    for(int i = 0;i<arr.size();i++){
        cout << arr[i] << endl;
    }

}