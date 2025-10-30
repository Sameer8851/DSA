#include <bits/stdc++.h>
using namespace std;

/*
--------------------------------------------------------------
🔥 LeetCode 96 | Unique Binary Search Trees
Author: Sameer Chaudhary
--------------------------------------------------------------
🧠 Problem:
Given an integer `n`, return the number of structurally unique 
BSTs (binary search trees) that store values 1 ... n.

--------------------------------------------------------------
💡 Example 1:
Input:  n = 3
Output: 5

💡 Example 2:
Input:  n = 1
Output: 1

--------------------------------------------------------------
Constraints:
1 ≤ n ≤ 19
--------------------------------------------------------------
*/

/*
--------------------------------------------------------------
🧩 Intuition:
--------------------------------------------------------------
- Each `i` from 1 to n can be chosen as the root.
- The number of BSTs with `i` as root =
      (Number of BSTs in left subtree) × (Number of BSTs in right subtree)
  → dp[i] = Σ (dp[left] × dp[right]) for all valid partitions.

This is the **Catalan Number** sequence:
    C(n) = Σ(C(i-1) * C(n-i)) for i = 1..n

--------------------------------------------------------------
🧮 Time Complexity:  O(n²)
🧮 Space Complexity: O(n)
--------------------------------------------------------------
*/

class Solution {
public:
    // ----------------------------------------------------------
    // 🧭 Recursive (Memoization) Approach
    // ----------------------------------------------------------
    int solve(int n, vector<int>& dp) {
        if (n <= 1) return 1;
        if (dp[n] != -1) return dp[n];

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += solve(i - 1, dp) * solve(n - i, dp);
        }
        return dp[n] = ans;
    }

    // ----------------------------------------------------------
    // ⚙️ Iterative (Tabulation) Approach
    // ----------------------------------------------------------
    int solveT(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }

    // ----------------------------------------------------------
    // 🚀 Main Function
    // ----------------------------------------------------------
    int numTrees(int n) {
        // Option 1: Recursive Memoized Approach
        // vector<int> dp(n + 1, -1);
        // return solve(n, dp);

        // Option 2: Iterative Tabulation Approach
        return solveT(n);
    }
};
