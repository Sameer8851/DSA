#include <bits/stdc++.h>
using namespace std;

/*
--------------------------------------------------------------
🔥 LeetCode 583 | Delete Operation for Two Strings
Author: Sameer Chaudhary
--------------------------------------------------------------
🧠 Problem:
Given two strings word1 and word2, return the minimum number of
steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.

--------------------------------------------------------------
💡 Example:
Input:  word1 = "sea", word2 = "eat"
Output: 2
Explanation:
Delete 's' from "sea" → "ea"
Delete 't' from "eat" → "ea"

--------------------------------------------------------------
Constraints:
1 <= word1.length, word2.length <= 500
word1 and word2 consist of only lowercase English letters.
--------------------------------------------------------------
*/

/*
--------------------------------------------------------------
🧩 Approach: Using Longest Common Subsequence (LCS)
--------------------------------------------------------------
🪄 Logic:
To make both strings equal, we only need to keep their
Longest Common Subsequence (LCS).

- Let LCS(word1, word2) = commonSub
- Then, we must delete all characters not in the LCS.
- So, answer = (len(word1) - commonSub) + (len(word2) - commonSub)
             = len(word1) + len(word2) - 2 * commonSub

--------------------------------------------------------------
Time Complexity:  O(n * m)
Space Complexity: O(n * m)
--------------------------------------------------------------
*/

class Solution {
public:
    int LCS(string& word1, string& word2, int i, int j, vector<vector<int>>& dp) {
        if (i >= word1.size() || j >= word2.size())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        if (word1[i] == word2[j])
            return dp[i][j] = 1 + LCS(word1, word2, i + 1, j + 1, dp);
        else
            return dp[i][j] = max(LCS(word1, word2, i + 1, j, dp),
                                  LCS(word1, word2, i, j + 1, dp));
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        int commonSub = LCS(word1, word2, 0, 0, dp);

        return n + m - 2 * commonSub;
    }
};
