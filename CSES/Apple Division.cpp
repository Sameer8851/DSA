
#include <bits/stdc++.h>
using namespace std;

long long solve(vector<long long>& arr,int i,long long sum,long long temp){
    if(i == arr.size()){
        return llabs(temp - (sum - temp));
    }
    long long exc = solve(arr,i+1,sum,temp);
    long long inc = solve(arr,i+1,sum,temp + arr[i]);
    return min(inc,exc);
}

int main(){
    int n;
    cin >> n;
    vector<long long> arr(n);
    long long sum = 0;
    for(int i = 0;i<n;i++){
        cin >> arr[i];
        sum += arr[i];
    }
    int result = solve(arr,0,sum,0);
    cout << result << endl;

}