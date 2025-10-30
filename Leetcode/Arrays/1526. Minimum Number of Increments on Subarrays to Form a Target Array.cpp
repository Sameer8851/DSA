#include <bits/stdc++.h>
using namespace std;

/*
--------------------------------------------------------------
🔥 LeetCode 1526 | Minimum Number of Increments on Subarrays 
   to Form a Target Array
Author: Sameer Chaudhary
--------------------------------------------------------------
🧠 Problem:
You are given an integer array `target` and an array `initial` 
(initially all zeros).  
In one operation, you can choose any subarray and increment 
each of its elements by one.  

Return the *minimum number of operations* required to make 
`initial` equal to `target`.

--------------------------------------------------------------
💡 Example 1:
Input:  target = [1,2,3,2,1]
Output: 3
Explanation:
[0,0,0,0,0] → +1 on [0..4]
[1,1,1,1,1] → +1 on [1..3]
[1,2,2,2,1] → +1 on [2..2]
Result = [1,2,3,2,1]

💡 Example 2:
Input:  target = [3,1,1,2]
Output: 4

💡 Example 3:
Input:  target = [3,1,5,4,2]
Output: 7
--------------------------------------------------------------
Constraints:
1 ≤ target.length ≤ 1e5
1 ≤ target[i] ≤ 1e5
--------------------------------------------------------------
*/

/*
--------------------------------------------------------------
🧩 Intuition:
--------------------------------------------------------------
- Each time we increase a subarray, it adds 1 to every element 
  in that range.
- The *total number of new increments* needed equals the sum of 
  all *positive increases* in the array.

💭 Example:
target = [1, 2, 3, 2, 1]
Differences:
[+1, +1, +1, -1, -1]
We only add up the positive changes (1 + 1 + 1 = 3).

So, the minimum number of operations =
    target[0] + Σ(max(0, target[i] - target[i-1]))

--------------------------------------------------------------
🧮 Time Complexity:  O(n)
🧮 Space Complexity: O(1)
--------------------------------------------------------------
*/

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans = target[0];

        for (int i = 1; i < target.size(); i++) {
            if (target[i] > target[i - 1]) {
                ans += target[i] - target[i - 1];
            }
        }

        return ans;
    }
};
