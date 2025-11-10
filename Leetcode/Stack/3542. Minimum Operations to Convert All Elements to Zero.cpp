#include <bits/stdc++.h>
using namespace std;

/*
--------------------------------------------------------------
🔥 LeetCode 3542 | Minimum Operations to Convert All Elements to Zero
Author: Sameer Chaudhary
--------------------------------------------------------------
🧠 Problem:
You are given an array `nums` of size `n`, consisting of non-negative integers.

In one operation, you can:
- Select a subarray `[i, j]` (0 ≤ i ≤ j < n), and
- Set all occurrences of the **minimum non-zero value** in that subarray to `0`.

Return the *minimum number of operations* required to make all elements in `nums` equal to `0`.

--------------------------------------------------------------
💡 Example 1:
Input:  nums = [0,2]
Output: 1
Explanation:
Select [1,1] → minimum is 2 → set all 2’s to 0 → [0,0].

💡 Example 2:
Input:  nums = [3,1,2,1]
Output: 3
Explanation:
1️⃣ Select [1,3] → min = 1 → [3,0,2,0]
2️⃣ Select [2,2] → min = 2 → [3,0,0,0]
3️⃣ Select [0,0] → min = 3 → [0,0,0,0]

💡 Example 3:
Input:  nums = [1,2,1,2,1,2]
Output: 4
Explanation:
1️⃣ [0,5] → min = 1 → [0,2,0,2,0,2]
2️⃣ [1,1] → min = 2 → [0,0,0,2,0,2]
3️⃣ [3,3] → min = 2 → [0,0,0,0,0,2]
4️⃣ [5,5] → min = 2 → [0,0,0,0,0,0]
--------------------------------------------------------------
Constraints:
1 ≤ n ≤ 1e5  
0 ≤ nums[i] ≤ 1e5
--------------------------------------------------------------
*/

/*
--------------------------------------------------------------
🧩 Intuition:
--------------------------------------------------------------
The key idea is that **each new increasing segment** in the array 
represents a new distinct operation.

Why?  
Whenever the current number `num` is greater than all previous numbers
in the stack, it forms a new "layer" that must be removed later.

Algorithm:
1️⃣ Use a **monotonic non-decreasing stack**.
2️⃣ Traverse through `nums`:
   - If `s.back() > num`, pop elements (since a smaller value resets the layer).
   - If `num > 0` and it’s greater than the last stack value, 
     increment `ans` (new operation) and push `num`.
3️⃣ Zeros are ignored since they are already 0 and need no operation.

This efficiently counts distinct non-overlapping "height segments"
that must each be zeroed out.

--------------------------------------------------------------
🧮 Time Complexity:  O(n)
🧮 Space Complexity: O(n)
--------------------------------------------------------------
*/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> s;  // Monotonic stack
        int ans = 0;

        for (int num : nums) {
            // Maintain a non-decreasing stack
            while (!s.empty() && s.back() > num) {
                s.pop_back();
            }

            // Skip zero values (already zero)
            if (num == 0) continue;

            // If new increasing element found → new operation
            if (s.empty() || s.back() < num) {
                ans++;
                s.push_back(num);
            }
        }

        return ans;
    }
};
