#include <bits/stdc++.h>
using namespace std;

/*
--------------------------------------------------------------
🔥 LeetCode 3370 | Smallest Number With All Set Bits
--------------------------------------------------------------
🧠 Problem:
Given a positive integer n, return the smallest number x 
such that:
    • x ≥ n
    • The binary representation of x contains only set bits (1’s)

--------------------------------------------------------------
💡 Example:
Input:  n = 5
Output: 7
Explanation:
Binary of 7 = "111" → All bits are set, and 7 ≥ 5.

--------------------------------------------------------------
Example 2:
Input:  n = 10
Output: 15
Binary of 15 = "1111"

Example 3:
Input:  n = 3
Output: 3
Binary of 3 = "11" (already all set)

--------------------------------------------------------------
Constraints:
1 <= n <= 1000
--------------------------------------------------------------
*/

/*
--------------------------------------------------------------
🧩 Approach:
--------------------------------------------------------------
We are looking for the smallest number ≥ n whose binary
representation has all bits set (i.e., 1, 3, 7, 15, 31, 63, ...).

These numbers are of the form:
        (2^k) - 1

So, we simply find the smallest (2^k - 1) that is ≥ n.

--------------------------------------------------------------
Time Complexity:  O(log n)
Space Complexity: O(1)
--------------------------------------------------------------
*/

class Solution {
public:
    int smallestNumber(int n) {
        int num = 1;

        // Keep doubling num to generate (2^k)
        for (int i = 0; i <= 1000; i++) {
            num *= 2;
            if (num - 1 >= n)
                return num - 1;
        }
        return -1; // Should never reach here for given constraints
    }
};
