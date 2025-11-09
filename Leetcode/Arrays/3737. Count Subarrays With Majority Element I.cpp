#include <bits/stdc++.h>
using namespace std;

/*
--------------------------------------------------------------
🔥 LeetCode 3737 | Count Subarrays With Majority Element I
Author: Sameer Chaudhary
--------------------------------------------------------------
🧠 Problem:
You are given an integer array `nums` and an integer `target`.

Return the number of *subarrays* of `nums` in which `target` is 
the **majority element**.

A majority element in a subarray appears **strictly more than half**
of the time in that subarray.

--------------------------------------------------------------
💡 Example 1:
Input:
nums = [1,2,2,3], target = 2
Output: 5

Explanation:
Valid subarrays where 2 is the majority element:
[2], [2], [2,2], [1,2,2], [2,2,3]

💡 Example 2:
Input:
nums = [1,1,1,1], target = 1
Output: 10
Explanation:
All subarrays have 1 as the majority element.

💡 Example 3:
Input:
nums = [1,2,3], target = 4
Output: 0
Explanation:
4 does not appear in nums at all, so no valid subarray exists.
--------------------------------------------------------------
Constraints:
1 ≤ nums.length ≤ 1000  
1 ≤ nums[i], target ≤ 1e9
--------------------------------------------------------------
*/

/*
--------------------------------------------------------------
🧩 Intuition:
--------------------------------------------------------------
A subarray `nums[i..j]` is valid if:
    count(target) * 2 > (j - i + 1)

We can brute-force all subarrays since `n ≤ 1000`:
1️⃣ For every starting index `i`, expand the subarray to `j`.
2️⃣ Keep track of how many times `target` appears.
3️⃣ If `target` count exceeds half the subarray length, 
    increment the answer.

--------------------------------------------------------------
🧮 Time Complexity:  O(n²)
🧮 Space Complexity: O(1)
--------------------------------------------------------------
*/

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int ans = 0;

        // Enumerate all subarrays
        for (int i = 0; i < nums.size(); i++) {
            int count = 0;
            for (int j = i; j < nums.size(); j++) {
                if (nums[j] == target)
                    count++;

                // Check majority condition
                if (count * 2 > (j - i + 1))
                    ans++;
            }
        }

        return ans;
    }
};
