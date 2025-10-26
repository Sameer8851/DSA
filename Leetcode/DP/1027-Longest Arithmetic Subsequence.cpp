/**
 * @file longest_arithmetic_subsequence.cpp
 * @brief Solution for LeetCode Problem 1027: Longest Arithmetic Subsequence
 * 
 * Given an array of integers `nums`, this program finds the length of the longest
 * arithmetic subsequence in the array. A subsequence is formed by deleting zero
 * or more elements without changing the order of the remaining elements.
 * 
 * Example:
 *   Input:  nums = [3,6,9,12]
 *   Output: 4
 *   Explanation: The entire array is an arithmetic sequence with difference = 3.
 * 
 * Time Complexity: O(n²)
 * Space Complexity: O(n²) (but sparse via unordered_map)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @brief Iterative DP solution for longest arithmetic subsequence.
     * 
     * dp[i][diff] = length of arithmetic subsequence ending at index i with difference diff.
     */
    int solveT(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2)
            return n;

        // Each index has a map: diff → length of subsequence ending at i
        vector<unordered_map<int, int>> dp(n);
        int ans = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int diff = nums[i] - nums[j];
                int len = 1;

                // If we already have a subsequence ending at j with the same diff
                if (dp[j].count(diff))
                    len = dp[j][diff];

                dp[i][diff] = len + 1;
                ans = max(ans, dp[i][diff]);
            }
        }

        return ans;
    }

    /**
     * @brief Public function called by LeetCode.
     */
    int longestArithSeqLength(vector<int>& nums) {
        return solveT(nums);
    }
};

#ifdef LOCAL_TEST
int main() {
    Solution sol;
    vector<int> nums1 = {3, 6, 9, 12};
    vector<int> nums2 = {9, 4, 7, 2, 10};
    vector<int> nums3 = {20, 1, 15, 3, 10, 5, 8};

    cout << "Example 1: " << sol.longestArithSeqLength(nums1) << endl; // 4
    cout << "Example 2: " << sol.longestArithSeqLength(nums2) << endl; // 3
    cout << "Example 3: " << sol.longestArithSeqLength(nums3) << endl; // 4

    return 0;
}
#endif
