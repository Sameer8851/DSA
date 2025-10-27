#include <bits/stdc++.h>
using namespace std;

/*
------------------------------------------------------------
🧩 Problem: 516. Longest Palindromic Subsequence
------------------------------------------------------------
Given a string `s`, find the length of the longest palindromic subsequence in `s`.

A subsequence is a sequence that can be derived from another sequence 
by deleting some or no elements without changing the order of the remaining elements.

------------------------------------------------------------
📘 Example 1:
Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".

📘 Example 2:
Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".

------------------------------------------------------------
🔒 Constraints:
1 <= s.length <= 1000
s consists only of lowercase English letters.
------------------------------------------------------------
🧠 Intuition:
The longest palindromic subsequence problem can be reframed as finding 
the **Longest Common Subsequence (LCS)** between the string `s` and its reverse `reverse(s)`.

- If we reverse the string and find the LCS between `s` and `reverse(s)`, 
  that LCS will naturally represent the longest subsequence that reads 
  the same forward and backward.

------------------------------------------------------------
⏱️ Time Complexity: O(n²)
📦 Space Complexity: O(n)
(Using bottom-up DP with space optimization)
------------------------------------------------------------
*/

class Solution {
public:
    // 🔹 Top-Down Recursive + Memoized Approach (for reference)
    int solve(string& s, string& rs, int i, int j, vector<vector<int>>& dp) {
        if (i >= s.length() || j >= rs.length())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        // If characters match, move both pointers forward
        if (s[i] == rs[j]) {
            return dp[i][j] = 1 + solve(s, rs, i + 1, j + 1, dp);
        } 
        // Else, take the maximum by skipping one character from either string
        else {
            return dp[i][j] = max(
                solve(s, rs, i + 1, j, dp),
                solve(s, rs, i, j + 1, dp)
            );
        }
    }

    // 🔹 Bottom-Up Tabulation (Space Optimized)
    int solveT(string s, string rs) {
        int n = s.length();
        vector<int> curr(n + 1, 0);
        vector<int> next(n + 1, 0);

        // Fill the DP table in reverse order (bottom-up)
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (s[i] == rs[j]) {
                    curr[j] = 1 + next[j + 1];
                } else {
                    curr[j] = max(next[j], curr[j + 1]);
                }
            }
            next = curr; // Move current row to next
        }
        return curr[0];
    }

    // 🔹 Main function
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        string reverseString = s;
        reverse(reverseString.begin(), reverseString.end());

        // Option 1: Recursive (Memoized) -> Uncomment if needed
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return solve(s, reverseString, 0, 0, dp);

        // Option 2: Bottom-Up (Recommended)
        return solveT(s, reverseString);
    }
};
