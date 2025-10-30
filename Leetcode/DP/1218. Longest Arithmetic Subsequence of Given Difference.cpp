#include <bits/stdc++.h>
using namespace std;

/*
--------------------------------------------------------------
🔥 LeetCode 1218 | Longest Arithmetic Subsequence of Given Difference
Author: Sameer Chaudhary
--------------------------------------------------------------
🧠 Problem:
Given an integer array `arr` and an integer `difference`,  
return the length of the *longest subsequence* such that the 
difference between adjacent elements equals `difference`.

A subsequence is formed by deleting some (or no) elements 
without changing the order of the remaining ones.

--------------------------------------------------------------
💡 Example 1:
Input:  arr = [1,2,3,4], difference = 1
Output: 4
Explanation: The entire array is an arithmetic subsequence.

💡 Example 2:
Input:  arr = [1,3,5,7], difference = 1
Output: 1

💡 Example 3:
Input:  arr = [1,5,7,8,5,3,4,2,1], difference = -2
Output: 4
Explanation: The longest arithmetic subsequence is [7,5,3,1].

--------------------------------------------------------------
Constraints:
1 ≤ arr.length ≤ 1e5  
-1e4 ≤ arr[i], difference ≤ 1e4
--------------------------------------------------------------
*/

/*
--------------------------------------------------------------
🧩 Intuition:
--------------------------------------------------------------
- Use a hash map `dp` where `dp[x]` represents the length of the 
  longest arithmetic subsequence ending with value `x`.
- For each element `arr[i]`, check if there exists `arr[i] - difference`.
  ▪ If yes → extend that subsequence.  
  ▪ If not → start a new subsequence with length 1.
- Keep track of the maximum length while iterating.

--------------------------------------------------------------
🧮 Time Complexity:  O(n)
🧮 Space Complexity: O(n)
--------------------------------------------------------------
*/

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> dp;
        int ans = 0;

        for (int i = 0; i < arr.size(); i++) {
            int prev = arr[i] - difference;
            dp[arr[i]] = dp[prev] + 1;  // extend or start new
            ans = max(ans, dp[arr[i]]);
        }

        return ans;
    }
};
