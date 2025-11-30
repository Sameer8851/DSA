#include <bits/stdc++.h>
using namespace std;

/*
--------------------------------------------------------------
🔥 LeetCode 646 | Maximum Length of Pair Chain
Author: Sameer Chaudhary
--------------------------------------------------------------
🧠 Problem:
You are given `n` pairs where each pair is of the form [a, b].
A pair [c, d] can follow [a, b] if **b < c**.

Return the *longest chain* you can form.

--------------------------------------------------------------
💡 Example 1:
Input:
pairs = [[1,2],[2,3],[3,4]]

Output:
2

Explanation:
Longest chain → [1,2] → [3,4]

💡 Example 2:
Input:
pairs = [[1,2],[7,8],[4,5]]

Output:
3

--------------------------------------------------------------
Constraints:
1 ≤ pairs.length ≤ 1000  
-1000 ≤ pairs[i][0] < pairs[i][1] ≤ 1000
--------------------------------------------------------------
*/

/*
--------------------------------------------------------------
🧩 Intuition:
--------------------------------------------------------------
This is similar to choosing non-overlapping intervals.

We sort all pairs by their starting value and apply:
✔ Recursion + Memoization (Top-Down DP)

At each index `curr`, we have two choices:
1️⃣ Take the current pair if it fits the chain:  
      if prev == -1 or pairs[curr][0] > pairs[prev][1]

2️⃣ Or skip current pair.

State:
dp[curr][prev+1] → +1 shift since prev = -1 is not a valid index.

--------------------------------------------------------------
🧮 Time Complexity:  O(n²)
🧮 Space Complexity: O(n²)
--------------------------------------------------------------
*/

class Solution {
public:
    // Top-Down recursion with memoization
    int solve(vector<vector<int>>& pairs, int curr, int prev,
              vector<vector<int>>& dp) {
        
        // Base case: Reached end
        if (curr == pairs.size()) return 0;

        // Already computed
        if (dp[curr][prev + 1] != -1)
            return dp[curr][prev + 1];

        // Option 1️⃣: Take current pair (if valid)
        int take = 0;
        if (prev == -1 || pairs[curr][0] > pairs[prev][1]) {
            take = 1 + solve(pairs, curr + 1, curr, dp);
        }

        // Option 2️⃣: Skip current pair
        int skip = solve(pairs, curr + 1, prev, dp);

        // Store and return best
        return dp[curr][prev + 1] = max(take, skip);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();

        // Sort pairs by first value
        sort(pairs.begin(), pairs.end());

        // dp[curr][prev+1]
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(pairs, 0, -1, dp);
    }
};
