#include <bits/stdc++.h>
using namespace std;

/*
 * Problem: 1781. Sum of Beauty of All Substrings
 * Link: https://leetcode.com/problems/sum-of-beauty-of-all-substrings/
 * Difficulty: Medium
 *
 * ------------------------------------------------------------
 * Description:
 * For a given string s, the "beauty" of a substring is defined as:
 *   (maximum frequency of any character) - (minimum frequency of any character)
 * across all characters that appear at least once.
 *
 * You need to calculate the total beauty of all possible substrings of s.
 *
 * ------------------------------------------------------------
 * Example:
 * Input:  s = "aabcb"
 * Output: 5
 * Explanation:
 *   The substrings with non-zero beauty are:
 *     "aab" → max=2, min=1 → beauty=1
 *     "aabc" → max=2, min=1 → beauty=1
 *     "aabcb" → max=2, min=1 → beauty=1
 *     "abcb" → max=2, min=1 → beauty=1
 *     "bcb" → max=2, min=1 → beauty=1
 *   Total beauty = 5
 *
 * ------------------------------------------------------------
 * Approach:
 * - Iterate over all possible starting indices `i`.
 * - Maintain a frequency array of size 26 for each character.
 * - For every ending index `j`, update frequency and compute:
 *     maxFreq = maximum frequency among present characters
 *     minFreq = minimum frequency among present characters (> 0)
 * - Add (maxFreq - minFreq) to total beauty sum.
 *
 * ------------------------------------------------------------
 * Complexity:
 * ⏱️ Time Complexity:  O(n² * 26) ≈ O(n²)
 * 📦 Space Complexity: O(26) = O(1)
 *
 * ------------------------------------------------------------
 */

class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            freq[s[i] - 'a']++; // Initialize with first char

            for (int j = i + 1; j < n; j++) {
                freq[s[j] - 'a']++;

                int maxFreq = 0;
                int minFreq = INT_MAX;

                // Find max and min frequency among characters that appear
                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0) {
                        maxFreq = max(maxFreq, freq[k]);
                        minFreq = min(minFreq, freq[k]);
                    }
                }

                ans += (maxFreq - minFreq);
            }
        }
        return ans;
    }
};
