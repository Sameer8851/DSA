#include <bits/stdc++.h>
using namespace std;

/*
 * Problem: 1220. Count Vowels Permutation
 * Link: https://leetcode.com/problems/count-vowels-permutation/
 * Difficulty: Hard
 *
 * Description:
 * Given an integer n, return the number of strings of length n that consist only
 * of vowels (a, e, i, o, u) and follow specific transition rules:
 *   - 'a' may only be followed by 'e', 'i', or 'u'
 *   - 'e' may only be followed by 'a' or 'i'
 *   - 'i' may only be followed by 'e' or 'o'
 *   - 'o' may only be followed by 'i'
 *   - 'u' may only be followed by 'i' or 'o'
 *
 * The answer may be large, so return it modulo 1e9 + 7.
 *
 * Approach:
 *   - Use dynamic programming (bottom-up tabulation).
 *   - Keep track of the number of valid strings ending with each vowel at step j.
 *   - Transition each vowel count based on the allowed following characters.
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(1)
 */

class Solution {
public:
    const int MOD = 1e9 + 7;

    int countVowelPermutation(int n) {
        long a = 1, e = 1, i = 1, o = 1, u = 1;
        long a2, e2, i2, o2, u2;

        // Build counts for strings of length j
        for (int j = 2; j <= n; j++) {
            a2 = (e + i + u) % MOD;  // 'a' follows 'e', 'i', or 'u'
            e2 = (a + i) % MOD;      // 'e' follows 'a' or 'i'
            i2 = (e + o) % MOD;      // 'i' follows 'e' or 'o'
            o2 = i % MOD;            // 'o' follows 'i'
            u2 = (i + o) % MOD;      // 'u' follows 'i' or 'o'

            a = a2, e = e2, i = i2, o = o2, u = u2;
        }

        return (a + e + i + o + u) % MOD;
    }
};
