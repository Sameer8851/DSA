/*
------------------------------------------------------------
🧩 Problem: 1027. Longest Arithmetic Subsequence
------------------------------------------------------------
Given an array of integers `nums`, find the length of the longest arithmetic
subsequence in the array.

A subsequence is formed by deleting zero or more elements without changing 
the order of the remaining elements.

------------------------------------------------------------
📘 Example 1:
Input: nums = [3,6,9,12]
Output: 4
Explanation: The entire array is an arithmetic sequence with difference = 3.

📘 Example 2:
Input: nums = [9,4,7,2,10]
Output: 3
Explanation: One longest arithmetic subsequence is [4,7,10].

------------------------------------------------------------
🔒 Constraints:
2 <= nums.length <= 1000
0 <= nums[i] <= 500
------------------------------------------------------------
🧠 Intuition:
For each element `nums[i]`, we want to know the longest arithmetic subsequence
that ends at `i` with a given difference `diff`.

We can use a DP table where:
    dp[i][diff] = length of arithmetic subsequence ending at index `i` with difference `diff`.

For each pair (j, i) with j < i:
    - Compute `diff = nums[i] - nums[j]`.
    - If dp[j][diff] exists, extend it: dp[i][diff] = dp[j][diff] + 1.
    - Otherwise, start a new subsequence: dp[i][diff] = 2.
    - Keep track of the maximum subsequence length.

------------------------------------------------------------
⏱️ Time Complexity: O(n²)
📦 Space Complexity: O(n²) (sparse due to use of unordered_map)
------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 🔹 Bottom-Up Dynamic Programming Approach
    int solveT(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;

        vector<unordered_map<int, int>> dp(n);  // dp[i][diff] = length ending at i with diff
        int ans = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int diff = nums[i] - nums[j];   // Calculate difference
                int len = 1;

                // If sequence with same diff ends at j, extend it
                if (dp[j].count(diff))
                    len = dp[j][diff];

                dp[i][diff] = len + 1;  // Extend subsequence or start new
                ans = max(ans, dp[i][diff]);
            }
        }
        return ans;
    }

    // 🔹 Main function
    int longestArithSeqLength(vector<int>& nums) {
        return solveT(nums);
    }
};