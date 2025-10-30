#include <bits/stdc++.h>
using namespace std;

/*
--------------------------------------------------------------
🔥 LeetCode 665 | Non-decreasing Array
Author: Sameer Chaudhary
--------------------------------------------------------------
🧠 Problem:
Given an integer array `nums` with `n` integers, your task is to 
check if it could become non-decreasing by modifying *at most one* element.

An array is **non-decreasing** if `nums[i] <= nums[i + 1]` holds 
for every valid index `i`.

--------------------------------------------------------------
💡 Example 1:
Input:  nums = [4,2,3]
Output: true
Explanation:
Modify the first 4 → 1 to get [1,2,3].

💡 Example 2:
Input:  nums = [4,2,1]
Output: false
Explanation:
You cannot make it non-decreasing with only one modification.

--------------------------------------------------------------
Constraints:
1 ≤ n ≤ 1e4  
-1e5 ≤ nums[i] ≤ 1e5
--------------------------------------------------------------
*/

/*
--------------------------------------------------------------
🧩 Intuition:
--------------------------------------------------------------
- We traverse the array to count where the order breaks (`nums[i-1] > nums[i]`).
- If this happens more than once → impossible with one modification.
- Otherwise, we try to "fix" the violation:
    - If it’s the first element or `nums[i-2] <= nums[i]`, 
      lower `nums[i-1]`.
    - Else, raise `nums[i]` to `nums[i-1]`.

Essentially, at most one correction is allowed.

--------------------------------------------------------------
🧮 Time Complexity:  O(n)
🧮 Space Complexity: O(1)
--------------------------------------------------------------
*/

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if (nums.size() <= 2) return true;

        int violation = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] > nums[i]) {
                violation++;
                if (violation > 1) return false;

                if (i == 1 || nums[i - 2] <= nums[i])
                    nums[i - 1] = nums[i];
                else
                    nums[i] = nums[i - 1];
            }
        }

        return true;
    }
};

