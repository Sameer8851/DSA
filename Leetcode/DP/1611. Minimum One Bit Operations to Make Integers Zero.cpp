#include <bits/stdc++.h>
using namespace std;

/*
--------------------------------------------------------------
🔥 LeetCode 1611 | Minimum One Bit Operations to Make Integers Zero
Author: Sameer Chaudhary
--------------------------------------------------------------
🧠 Problem:
You are given an integer `n`. In one operation, you can change the i-th bit of `n` (0 ≤ i < 30)
**if and only if** all bits to the right of the i-th bit are 0.

Return the *minimum number of operations* required to make `n = 0`.

--------------------------------------------------------------
💡 Example 1:
Input:  n = 3
Output: 2
Explanation:
011 → 001 → 000

💡 Example 2:
Input:  n = 6
Output: 4
Explanation:
110 → 111 → 101 → 100 → 000
--------------------------------------------------------------
Constraints:
0 ≤ n ≤ 1e9
--------------------------------------------------------------
*/

/*
--------------------------------------------------------------
🧩 Intuition:
--------------------------------------------------------------
This problem is based on **reverse Gray code** transformation.

- The number of steps required to turn `n` into 0 is equal to its Gray code rank.
- For a bit at position `i`, the number of steps to clear it (if it’s set)
  follows the pattern:
  
  F[i] = 2^(i + 1) - 1  → [1, 3, 7, 15, 31, ...]

- We alternate between adding and subtracting these F[i] values based on 
  whether we’ve flipped an odd or even number of set bits so far.
  (Hence the `sign` variable toggling.)

--------------------------------------------------------------
🧮 Time Complexity:  O(1)
🧮 Space Complexity: O(1)
--------------------------------------------------------------
*/

class Solution {
public:
    int minimumOneBitOperations(int n) {
        if (n == 0) return 0;

        // Precompute F[i] = 2^(i+1) - 1
        vector<long long> F(31, 0);
        F[0] = 1;
        for (int i = 1; i <= 30; i++) {
            F[i] = 2 * F[i - 1] + 1;
        }

        int result = 0;
        int sign = 1;

        // Traverse bits from MSB to LSB
        for (int i = 30; i >= 0; i--) {
            int ith_bit = (1 << i) & n;
            if (ith_bit == 0) continue;

            if (sign > 0)
                result += F[i];
            else
                result -= F[i];

            sign = -sign; // Toggle sign for next set bit
        }

        return result;
    }
};
