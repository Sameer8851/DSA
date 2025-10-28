#include <bits/stdc++.h>
using namespace std;

/*
--------------------------------------------------------------
🔥 LeetCode 5 | Longest Palindromic Substring
Author: Sameer Chaudhary
--------------------------------------------------------------
🧠 Problem:
Given a string s, return the longest palindromic substring in s.

A palindrome reads the same forward and backward.

--------------------------------------------------------------
💡 Example:
Input:  s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

--------------------------------------------------------------
Constraints:
1 <= s.length <= 1000
s consists of only digits and English letters.
--------------------------------------------------------------
*/

/*
--------------------------------------------------------------
🧩 Approach 1: Top-Down Dynamic Programming (Memoized Recursion)
--------------------------------------------------------------
Logic:
1️⃣ Define isPalindrome(s, l, r) → returns true if s[l...r] is palindrome.
2️⃣ Base case: l >= r → true.
3️⃣ If s[l] == s[r], recursively check inner substring.
4️⃣ Store results in dp[l][r] to avoid recomputation.
5️⃣ Try every substring and keep track of longest valid palindrome.

Time Complexity:  O(n²)
Space Complexity: O(n²)
--------------------------------------------------------------
*/

class SolutionDP {
public:
    bool isPalindrome(const string &s, int left, int right, vector<vector<int>> &dp) {
        if (left >= right) return true;
        if (dp[left][right] != -1) return dp[left][right];

        if (s[left] == s[right])
            return dp[left][right] = isPalindrome(s, left + 1, right - 1, dp);
        else
            return dp[left][right] = false;
    }

    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 0) return "";

        vector<vector<int>> dp(n, vector<int>(n, -1));
        string longest = s.substr(0, 1);

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPalindrome(s, i, j, dp) && (j - i + 1 > (int)longest.length())) {
                    longest = s.substr(i, j - i + 1);
                }
            }
        }
        return longest;
    }
};

/*
--------------------------------------------------------------
🧩 Approach 2: Expand Around Center (Optimal O(1) Space)
--------------------------------------------------------------
Logic:
1️⃣ Every palindrome has a center — single (odd) or pair (even).
2️⃣ Expand outward while s[left] == s[right].
3️⃣ Keep track of the longest palindrome seen.

Time Complexity:  O(n²)
Space Complexity: O(1)
--------------------------------------------------------------
*/

class SolutionExpandCenter {
public:
    pair<int, int> expandFromCenter(const string &s, int left, int right) {
        int n = s.size();
        while (left >= 0 && right < n && s[left] == s[right]) {
            left--;
            right++;
        }
        return {left + 1, right - 1}; // valid palindrome bounds
    }

    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        int start = 0, end = 0;

        for (int i = 0; i < n; i++) {
            auto [l1, r1] = expandFromCenter(s, i, i);     // Odd length
            auto [l2, r2] = expandFromCenter(s, i, i + 1); // Even length

            if (r1 - l1 > end - start) {
                start = l1;
                end = r1;
            }
            if (r2 - l2 > end - start) {
                start = l2;
                end = r2;
            }
        }

        return s.substr(start, end - start + 1);
    }
};
