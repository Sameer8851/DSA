#include <bits/stdc++.h>
using namespace std;

/*
--------------------------------------------------------------
🔥 LeetCode 1846 | Maximum Element After Decreasing and Rearranging
Author: Sameer Chaudhary
--------------------------------------------------------------
🧠 Problem:
You are given an integer array `arr`.  

You can perform the following two operations any number of times:
1️⃣ Decrease any element of the array.
2️⃣ Rearrange the elements in any order.

Return the *maximum possible value* of the smallest element at the last index  
such that after rearrangement, the following conditions hold:
- arr[0] == 1  
- |arr[i] - arr[i - 1]| <= 1 for every i > 0

--------------------------------------------------------------
💡 Example 1:
Input:
arr = [2,2,1,2,1]
Output: 2

Explanation:
After rearranging: [1,1,2,2,2]
- arr[0] = 1  
- Differences are ≤ 1  
- Maximum element = 2

💡 Example 2:
Input:
arr = [100,1,1000]
Output: 3

Explanation:
After rearranging → [1,2,3], all conditions are met.

💡 Example 3:
Input:
arr = [1,2,3,4,5]
Output: 5

--------------------------------------------------------------
Constraints:
1 ≤ arr.length ≤ 10⁵  
1 ≤ arr[i] ≤ 10⁹
--------------------------------------------------------------
*/

/*
--------------------------------------------------------------
🧩 Intuition:
--------------------------------------------------------------
To maximize the final element:
1️⃣ Sort the array (since we can rearrange freely).
2️⃣ Set arr[0] = 1 (it must start at 1).
3️⃣ For every subsequent element:
   - If the current element is larger than the previous + 1,  
     reduce it to `arr[i-1] + 1`.
   - This ensures the absolute difference ≤ 1.
4️⃣ Track the maximum element reached during this process.

Since we’re only ever reducing elements and maintaining valid order,
the last value will automatically be the maximum possible.

--------------------------------------------------------------
🧮 Time Complexity:  O(n log n)
🧮 Space Complexity: O(1)
--------------------------------------------------------------
*/

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();

        // Step 1️⃣: Handle single element edge case
        if (n == 1) return 1;

        // Step 2️⃣: Ensure first element is 1
        arr[0] = 1;
        int maxE = 1;

        // Step 3️⃣: Adjust all elements to maintain |arr[i] - arr[i-1]| <= 1
        for (int i = 1; i < n; i++) {
            if (abs(arr[i] - arr[i - 1]) > 1) {
                arr[i] = arr[i - 1] + 1;
            }
            maxE = max(maxE, arr[i]);
        }

        return maxE;
    }
};
