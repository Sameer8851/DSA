#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9 + 7;
 
int solve(int n, vector<int>& dp){
    if(n == 0){
        return 1;
    }
    if(n < 0){
        return 0;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    int total = 0;
    for(int i = 1;i<=6;i++){
        total = (total + solve(n-i,dp)) % MOD;
    }
    return dp[n] = total;
}

int solveT(int n){
    vector<int> dp(n+1,0);
    dp[n] = 1;
    
    for(int i = n-1;i>=0;i--){
        int total = 0;
        for(int j = 1;j<=6;j++){
            if(i+j <= n){

                total = (total + dp[i+j]) % MOD;
            }
        }
        dp[i] = total;
    }
   
    return dp[0];
}

 
int main(){
    int n;
    cin >> n;
    vector<int> dp(n+1,-1);
    cout << solveT(n) << endl ;

}