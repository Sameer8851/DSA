#include <bits/stdc++.h>
using namespace std;

/*
--------------------------------------------
🧠 Problem: 647. Palindromic Substrings
--------------------------------------------
Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.
A substring is a contiguous sequence of characters within the string.

--------------------------------------------
💡 Example:
Input: s = "aaa"
Output: 6
Explanation: Six palindromic substrings - "a","a","a","aa","aa","aaa"

--------------------------------------------
🧩 Approach 1: Dynamic Programming (Bottom-Up)
--------------------------------------------
1️⃣ dp[i][j] = true if substring s[i...j] is palindrome.
2️⃣ Base cases:
      - Single letters are palindrome.
      - Two letters are palindrome if s[i] == s[j].
3️⃣ For length > 2, s[i...j] is palindrome if:
      - s[i] == s[j] && dp[i+1][j-1] == true
4️⃣ Count all dp[i][j] that are true.

Time Complexity: O(n²)
Space Complexity: O(n²)
--------------------------------------------
*/

class SolutionDP {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int count = 0;

        // Iterate over substring lengths
        for (int L = 1; L <= n; L++) {
            for (int i = 0; i + L - 1 < n; i++) {
                int j = i + L - 1; // end index

                if (i == j) {
                    dp[i][j] = true; // single character
                } 
                else if (i + 1 == j) {
                    dp[i][j] = (s[i] == s[j]); // two characters
                } 
                else {
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }

                if (dp[i][j]) count++;
            }
        }
        return count;
    }
};

/*
--------------------------------------------
🧩 Approach 2: Expand Around Center
--------------------------------------------
1️⃣ For each character in string:
     - Consider it as center of odd length palindrome.
     - Consider pair (i, i+1) as center of even length palindrome.
2️⃣ Expand outward while left and right match.
3️⃣ Count every valid palindrome found.

Time Complexity: O(n²)
Space Complexity: O(1)
--------------------------------------------
*/

class SolutionExpandCenter {
public:
    int expandFromCenter(const string &s, int left, int right) {
        int count = 0;
        int n = s.size();

        while (left >= 0 && right < n && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
        return count;
    }

    int countSubstrings(string s) {
        int total = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            // Odd length palindrome (center at i)
            total += expandFromCenter(s, i, i);
            // Even length palindrome (center between i and i+1)
            total += expandFromCenter(s, i, i + 1);
        }
        return total;
    }
};

