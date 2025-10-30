#include <bits/stdc++.h>
using namespace std;

/*
--------------------------------------------------------------
🔥 LeetCode 1647 | Minimum Deletions to Make Character Frequencies Unique
Author: Sameer Chaudhary
--------------------------------------------------------------
🧠 Problem:
A string `s` is called *good* if no two different characters have the same frequency.

Return the *minimum number of deletions* required to make `s` good.

--------------------------------------------------------------
💡 Example 1:
Input:  s = "aab"
Output: 0
Explanation: The string is already good.

💡 Example 2:
Input:  s = "aaabbbcc"
Output: 2
Explanation:
Possible good strings → "aaabcc" or "aaabbc".

💡 Example 3:
Input:  s = "ceabaacb"
Output: 2
Explanation:
Delete both 'c's → "eabaab", which is good.
--------------------------------------------------------------
Constraints:
1 ≤ s.length ≤ 1e5  
s contains only lowercase English letters.
--------------------------------------------------------------
*/

/*
--------------------------------------------------------------
🧩 Intuition:
--------------------------------------------------------------
- Count how many times each character appears.
- To make all frequencies unique:
  ▪ If a frequency is already used, we must reduce it 
    (delete characters) until it becomes unused.
  ▪ Store all used frequencies in a `set` to ensure uniqueness.

🎯 Example:
s = "aaabbbcc"
Frequencies → [3,3,2]
- First 3 → ok
- Second 3 → already used → reduce to 2 (used) → reduce to 1 (unique)
- 2 → already used → reduce to 0 (delete all)
Total deletions = 2

--------------------------------------------------------------
🧮 Time Complexity:  O(n)
🧮 Space Complexity: O(1)
--------------------------------------------------------------
*/

class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        for (char ch : s)
            freq[ch - 'a']++;

        unordered_set<int> used;  // stores used frequencies
        int deletions = 0;

        for (int f : freq) {
            while (f > 0 && used.count(f)) {
                f--;            // reduce until unique
                deletions++;    // count each deletion
            }
            if (f > 0)
                used.insert(f);
        }
        return deletions;
    }
};
