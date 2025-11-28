#include <bits/stdc++.h>
using namespace std;

/*
--------------------------------------------------------------
🔥 LeetCode 712 | Minimum ASCII Delete Sum for Two Strings
Author: Sameer Chaudhary
--------------------------------------------------------------
🧠 Problem:
You are given two strings `s1` and `s2`.

You need to make the strings equal by deleting characters.
The cost of deleting a character is the ASCII value of that character.

Return the **minimum total ASCII delete sum** required to make both
strings equal.

--------------------------------------------------------------
💡 Example 1:
Input:
s1 = "sea", s2 = "eat"
Output: 231

Explanation:
Delete 's' (115) from s1  
Delete 't' (116) from s2  
Total = 231

💡 Example 2:
Input:
s1 = "delete", s2 = "leet"
Output: 403

--------------------------------------------------------------
Constraints:
1 ≤ s1.length, s2.length ≤ 1000  
s1 and s2 consist of lowercase English letters.
--------------------------------------------------------------
*/

/*
--------------------------------------------------------------
🧩 Intuition:
--------------------------------------------------------------
This problem is identical to:
→ Minimum deletions needed to make both strings equal  
→ But each deletion costs the ASCII value of the character.

We use **DP with recursion + memoization**:

Let dp[i][j] = minimum ASCII delete sum to make:
    s1[i:] and s2[j:] equal.

Cases:
1️⃣ If characters match:
      s1[i] == s2[j]
      → No deletion needed → move both pointers.

2️⃣ If characters do NOT match:
      Delete s1[i]  → cost = s1[i] + solve(i+1, j)
      Delete s2[j]  → cost = s2[j] + solve(i, j+1)
      Take the minimum.

3️⃣ If one string ends:
      Must delete all remaining characters of the other.

--------------------------------------------------------------
🧮 Time Complexity:  O(n * m)
🧮 Space Complexity: O(n * m)
--------------------------------------------------------------
*/

class Solution {
public:
    int solve(string& text1, string& text2, int i, int j,
              vector<vector<int>>& dp) {

        // Case 1: s1 is exhausted
        if (i == text1.size()) {
            int sum = 0;
            for (int k = j; k < text2.size(); k++)
                sum += text2[k];
            return sum;
        }

        // Case 2: s2 is exhausted
        if (j == text2.size()) {
            int sum = 0;
            for (int k = i; k < text1.size(); k++)
                sum += text1[k];
            return sum;
        }

        // Memoized result
        if (dp[i][j] != -1)
            return dp[i][j];

        // Case 3: Characters match
        if (text1[i] == text2[j]) {
            return dp[i][j] = solve(text1, text2, i + 1, j + 1, dp);
        }

        // Case 4: Characters do not match
        int deleteFromS1 = text1[i] + solve(text1, text2, i + 1, j, dp);
        int deleteFromS2 = text2[j] + solve(text1, text2, i, j + 1, dp);

        return dp[i][j] = min(deleteFromS1, deleteFromS2);
    }

    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return solve(s1, s2, 0, 0, dp);
    }
};
