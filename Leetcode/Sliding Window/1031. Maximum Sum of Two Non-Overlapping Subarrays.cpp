#include <bits/stdc++.h>
using namespace std;

/*
--------------------------------------------------------------
🔥 LeetCode 1031 | Maximum Sum of Two Non-Overlapping Subarrays
Author: Sameer Chaudhary
--------------------------------------------------------------
🧠 Problem:
Given an array `nums`, and two integers `firstLen` and `secondLen`,  
find the **maximum sum** of two **non-overlapping** subarrays:

- One subarray must have length = firstLen
- One subarray must have length = secondLen

Order does not matter:  
▪ firstLen can come before secondLen  
▪ or secondLen can come before firstLen

--------------------------------------------------------------
💡 Example 1:
Input:
nums = [0,6,5,2,2,5,1,9,4]
firstLen = 1  
secondLen = 2  

Output: 20

Explanation:
Two subarrays:
[9] (sum = 9)  
[6,5] (sum = 11)  
Total = 20

💡 Example 2:
Input:
nums = [3,8,1,3,2,1,8,9,0]
firstLen = 3  
secondLen = 2  

Output: 29

--------------------------------------------------------------
Constraints:
1 ≤ nums.length ≤ 1000  
1 ≤ firstLen, secondLen ≤ nums.length
--------------------------------------------------------------
*/

/*
--------------------------------------------------------------
🧩 Intuition:
--------------------------------------------------------------
We want two non-overlapping subarrays with maximum total sum.

We compute:
1) Prefix sum array → quick range sum queries.
2) For each index, maintain:
   - best sum of a firstLen subarray ending *before* the current window
   - best sum of a secondLen subarray ending *before* the current window

We compute answer twice:
✔ firstLen comes before secondLen  
✔ secondLen comes before firstLen  

Take the maximum.

--------------------------------------------------------------
🧮 Time Complexity:  O(n)
🧮 Space Complexity: O(n)
--------------------------------------------------------------
*/

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();

        // Step 1️⃣: Prefix sum
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        int ans = 0;

        // Case A️⃣: firstLen before secondLen
        int bestF = 0;  // best firstLen subarray seen so far
        for (int i = firstLen + secondLen; i <= n; i++) {
            bestF = max(bestF,
                        prefix[i - secondLen] - prefix[i - secondLen - firstLen]);

            // secondLen subarray at the end
            int secondSum = prefix[i] - prefix[i - secondLen];

            ans = max(ans, bestF + secondSum);
        }

        // Case B️⃣: secondLen before firstLen
        int bestS = 0;  // best secondLen subarray seen so far
        for (int i = firstLen + secondLen; i <= n; i++) {
            bestS = max(bestS,
                        prefix[i - firstLen] - prefix[i - firstLen - secondLen]);

            // firstLen subarray at the end
            int firstSum = prefix[i] - prefix[i - firstLen];

            ans = max(ans, bestS + firstSum);
        }

        return ans;
    }
};
