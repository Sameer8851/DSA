#include <bits/stdc++.h>
using namespace std;

/*
------------------------------------------------------------
🧩 Problem: 395. Longest Substring with At Least K Repeating Characters
------------------------------------------------------------
Given a string `s` and an integer `k`, return the length of the **longest substring**
of `s` such that **every character** in the substring appears at least `k` times.

If no such substring exists, return `0`.

------------------------------------------------------------
📘 Example 1:
Input:  s = "aaabb", k = 3
Output: 3
Explanation: The longest valid substring is "aaa" (each character appears ≥ 3 times).

📘 Example 2:
Input:  s = "ababbc", k = 2
Output: 5
Explanation: The longest valid substring is "ababb" 
('a' appears 2 times, 'b' appears 3 times).

------------------------------------------------------------
🔒 Constraints:
- 1 <= s.length <= 10⁴
- s consists of only lowercase English letters.
- 1 <= k <= 10⁵
------------------------------------------------------------
🧠 Intuition:
The key idea is **Divide and Conquer**:
1️⃣ Count the frequency of each character.
2️⃣ If any character occurs fewer than `k` times, it **cannot be part of a valid substring**.
3️⃣ Split the string at that character and recursively solve for both sides.
4️⃣ The answer is the maximum of both results.
5️⃣ If all characters meet the `k` condition, the whole string is valid.

------------------------------------------------------------
⚙️ Approach:
- Use recursion to divide the string around invalid characters.
- Base case: if all characters are valid, return the string’s length.
- Recursive step: find characters that occur < k, split, and check both sides.

------------------------------------------------------------
⏱️ Time Complexity: O(n²)
   (Because of substring creation in recursive calls)
📦 Space Complexity: O(1)  (Ignoring recursion stack)
------------------------------------------------------------
*/

class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        unordered_map<char, int> freq;

        // Count frequency of each character in current substring
        for (char ch : s)
            freq[ch]++;

        // Split the string at characters occurring less than k times
        for (int i = 0; i < n; i++) {
            if (freq[s[i]] < k) {
                // Divide and Conquer: split and check both halves
                int left = longestSubstring(s.substr(0, i), k);
                int right = longestSubstring(s.substr(i + 1), k);
                return max(left, right);
            }
        }

        // All characters meet the k condition → entire string is valid
        return n;
    }
};

