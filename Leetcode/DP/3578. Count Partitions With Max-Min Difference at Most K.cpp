#include <bits/stdc++.h>
using namespace std;

/*
--------------------------------------------------------------
🔥 LeetCode 3259 | Count Partitions With Fixed Difference
Author: Sameer Chaudhary
--------------------------------------------------------------
🧠 Problem:
You are given an array `nums` and an integer `k`.

We need to count the number of ways to partition the array into
consecutive groups such that **every group's max - min ≤ k**.

Return the number of valid partitions modulo 1e9+7.

--------------------------------------------------------------
💡 Example:
nums = [1,3,2], k = 2

Possible partitions where each group's (max - min ≤ k):
- [1] | [3] | [2]
- [1,3] | [2]
- [1,3,2]
- [1] | [3,2]

Output: 4
--------------------------------------------------------------
Constraints:
1 ≤ nums.length ≤ 10⁵  
0 ≤ nums[i] ≤ 10⁹  
0 ≤ k ≤ 10⁹  
--------------------------------------------------------------
*/

/*
--------------------------------------------------------------
🧩 Intuition:
--------------------------------------------------------------
We use **DP + Sliding Window + Monotonic Queues**.

Let dp[i] = number of valid partitions for prefix nums[0..i-1].

For each ending index `right`, we find the **leftmost valid index**
such that:
        max(nums[left..right]) - min(nums[left..right]) ≤ k

To maintain max & min efficiently:
✔ Use a decreasing deque for maximum  
✔ Use an increasing deque for minimum  

We maintain a range [left..right] that satisfies the condition.

Then:
dp[right+1] = sum of all dp[left..right]
We maintain prefix sums to compute this in O(1).

--------------------------------------------------------------
🧮 Time Complexity:  O(n)
🧮 Space Complexity: O(n)
--------------------------------------------------------------
*/

class Solution {
public:
    const int MOD = 1e9 + 7;

    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> dp(n + 1), prefix(n + 1);
        dp[0] = 1;             // empty partition
        prefix[0] = 1;         // prefix sum for dp

        deque<int> maxQ, minQ; // monotonic queues
        int left = 0;

        for (int right = 0; right < n; right++) {

            // Maintain decreasing deque for max
            while (!maxQ.empty() && nums[maxQ.back()] <= nums[right])
                maxQ.pop_back();
            maxQ.push_back(right);

            // Maintain increasing deque for min
            while (!minQ.empty() && nums[minQ.back()] >= nums[right])
                minQ.pop_back();
            minQ.push_back(right);

            // Shrink window until valid
            while (nums[maxQ.front()] - nums[minQ.front()] > k) {
                if (maxQ.front() == left) maxQ.pop_front();
                if (minQ.front() == left) minQ.pop_front();
                left++;
            }

            // dp[right+1] = sum(dp[left] ... dp[right])
            int ways = prefix[right];
            if (left > 0)
                ways = (ways - prefix[left - 1] + MOD) % MOD;

            dp[right + 1] = ways;
            prefix[right + 1] = (prefix[right] + dp[right + 1]) % MOD;
        }

        return dp[n];
    }
};
