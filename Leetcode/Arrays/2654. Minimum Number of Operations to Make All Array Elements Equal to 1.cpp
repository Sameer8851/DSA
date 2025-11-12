#include <bits/stdc++.h>
using namespace std;

/*
--------------------------------------------------------------
🔥 LeetCode 2654 | Minimum Number of Operations to Make All Array Elements Equal to 1
Author: Sameer Chaudhary
--------------------------------------------------------------
🧠 Problem:
You are given an integer array `nums`.  

In one operation, you can:
- Choose any **subarray** `[i, j]`, and  
- Replace each element in that subarray with the **GCD** of all its elements.

Return the *minimum number of operations* required to make every element of `nums` equal to `1`.  
If it is not possible, return `-1`.

--------------------------------------------------------------
💡 Example 1:
Input:
nums = [2,6,3,4]
Output: 4
Explanation:
Step 1️⃣: Subarray [1,2] → gcd(6,3)=3 → [2,3,3,4]  
Step 2️⃣: Subarray [0,1] → gcd(2,3)=1 → [1,1,3,4]  
Step 3️⃣: Subarray [2,2] → gcd(3)=3 → [1,1,3,4]  
Step 4️⃣: Subarray [2,3] → gcd(3,4)=1 → [1,1,1,1]  

Total operations = 4.

💡 Example 2:
Input:
nums = [2,10,6,14]
Output: -1
Explanation:
Overall GCD = 2 → cannot make all 1s.

--------------------------------------------------------------
Constraints:
1 ≤ nums.length ≤ 2000  
1 ≤ nums[i] ≤ 10⁶
--------------------------------------------------------------
*/

/*
--------------------------------------------------------------
🧩 Intuition:
--------------------------------------------------------------
To make all elements 1 using GCD operations:
1️⃣ If the overall GCD of the array > 1,  
    → impossible to make any element 1 → return -1.

2️⃣ If there’s already a `1` in the array:
    → Each non-1 element can be turned into 1 by one operation →  
      Answer = (n - count(1)).

3️⃣ Otherwise:
    - Find the **shortest subarray** whose GCD = 1.  
      (That’s the first step to create at least one `1`.)
    - Once we have a `1`, we can make all others 1 in `(n - 1)` more operations.

Thus:
    totalOps = (length_of_shortest_subarray_with_gcd_1 - 1) + (n - 1)

--------------------------------------------------------------
🧮 Time Complexity:  O(n²)  — nested GCD checks
🧮 Space Complexity: O(1)
--------------------------------------------------------------
*/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        // Step 1️⃣: Check if overall GCD != 1 → impossible
        int overallGCD = nums[0];
        for (int i = 1; i < n; ++i)
            overallGCD = gcd(overallGCD, nums[i]);
        if (overallGCD != 1)
            return -1;

        // Step 2️⃣: If array already contains 1s
        int ones = count(nums.begin(), nums.end(), 1);
        if (ones > 0)
            return n - ones;

        // Step 3️⃣: Find the shortest subarray with GCD == 1
        int minLen = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int currGCD = nums[i];
            for (int j = i + 1; j < n; ++j) {
                currGCD = gcd(currGCD, nums[j]);
                if (currGCD == 1) {
                    minLen = min(minLen, j - i + 1);
                    break;  // no need to check longer subarrays
                }
            }
        }

        // Step 4️⃣: Total operations = (minLen - 1) + (n - 1)
        return (minLen - 1) + (n - 1);
    }
};
