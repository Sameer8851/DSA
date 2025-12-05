#include <bits/stdc++.h>
using namespace std;

/*
--------------------------------------------------------------
🔥 LeetCode 174 | Dungeon Game
Author: Sameer Chaudhary
--------------------------------------------------------------
🧠 Problem:
A knight must travel from the top-left of a dungeon to the bottom-right.
Each cell contains either:
  🔹 A negative value (damage),
  🔹 A positive value (health bonus), or
  🔹 Zero.

The knight:
- Can only move RIGHT or DOWN.
- Must always have health ≥ 1.
- Starts with minimum possible health so he **never dies**.

Return the *minimum initial health required*.

--------------------------------------------------------------
💡 Example 1:
Input:
[[-2,-3,3],
 [-5,-10,1],
 [10,30,-5]]

Output: 7

Explanation:
Minimum health = 7 ensures survival for all paths.

--------------------------------------------------------------
Constraints:
1 ≤ m, n ≤ 200
-1000 ≤ dungeon[i][j] ≤ 1000
--------------------------------------------------------------
*/

/*
--------------------------------------------------------------
🧩 Intuition:
--------------------------------------------------------------
This is a **reverse DP** problem disguised as forward recursion.

At each cell (i, j), the knight must ensure that after taking the
cell’s value `mat[i][j]`, he still has enough health for the next cell.

We solve using DP:
- Let `dp[i][j]` = minimum health required *upon entering* (i, j).
- Base case: At bottom-right:
      If cell value ≥ 0 → need at least 1 health
      If cell value < 0  → need (-value + 1)

Transition:
- From (i, j), the knight can go RIGHT or DOWN.
- Choose the path requiring *less* health.
- Required = min(right, down) - mat[i][j]
- Ensure result ≥ 1 always.

--------------------------------------------------------------
🧮 Time Complexity:  O(n × m)
🧮 Space Complexity: O(n × m)
--------------------------------------------------------------
*/

class Solution {
public:
    // Top-Down recursion with memoization
    int solve(vector<vector<int>>& mat, int i, int j,
              vector<vector<int>>& dp) {

        int n = mat.size();
        int m = mat[0].size();

        // Out of bounds → invalid path → large value
        if (i == n || j == m) return INT_MAX;

        // Base case: bottom-right cell
        if (i == n - 1 && j == m - 1)
            return (mat[i][j] <= 0) ? -mat[i][j] + 1 : 1;

        // Memoized
        if (dp[i][j] != -1) return dp[i][j];

        // Explore next moves
        int right = solve(mat, i, j + 1, dp);
        int down  = solve(mat, i + 1, j, dp);

        // Minimum health needed from next step
        int minNext = min(right, down);

        int minHealthRequired = minNext - mat[i][j];

        // Must be at least 1
        return dp[i][j] = (minHealthRequired <= 0) ? 1 : minHealthRequired;
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), m = dungeon[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(dungeon, 0, 0, dp);
    }
};
