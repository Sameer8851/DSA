#include <bits/stdc++.h>
using namespace std;

/*
--------------------------------------------------------------
🔥 LeetCode 2257 | Count Unguarded Cells in the Grid
Author: Sameer Chaudhary
--------------------------------------------------------------
🧠 Problem:
You are given an m x n grid with some guards and walls.
Each guard can see every cell in their row and column **until**
their vision is blocked by a wall or another guard.

Return the *number of unguarded cells*.

--------------------------------------------------------------
💡 Example 1:
Input:
m = 4, n = 6
guards = [[0,0],[1,1],[2,3]]
walls = [[0,1],[2,2],[1,4]]

Output: 7

--------------------------------------------------------------
💡 Example 2:
Input:
m = 3, n = 3
guards = [[1,1]]
walls = [[0,1],[1,0],[2,1],[1,2]]

Output: 4
--------------------------------------------------------------
Constraints:
1 ≤ m, n ≤ 1e5 (total cells ≤ 1e5)
1 ≤ guards.length, walls.length ≤ 1e5
--------------------------------------------------------------
*/

/*
--------------------------------------------------------------
🧩 Intuition:
--------------------------------------------------------------
- We'll simulate guard vision using **four directional sweeps**:
  → Left→Right, Right→Left, Top→Bottom, Bottom→Top
- Each guard can "see" in straight lines until blocked by wall/guard.
- After marking all guarded cells, we count how many remain unguarded.

--------------------------------------------------------------
⚙️ Grid Encoding:
  0 = empty cell  
  1 = wall  
  2 = guard  
  3 = guarded cell

--------------------------------------------------------------
🧮 Time Complexity:  O(m * n)
🧮 Space Complexity: O(m * n)
--------------------------------------------------------------
*/

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        // Step 1️⃣: Mark guards and walls
        for (auto &g : guards) grid[g[0]][g[1]] = 2;
        for (auto &w : walls)  grid[w[0]][w[1]] = 1;

        // Step 2️⃣: Left → Right sweep
        for (int i = 0; i < m; i++) {
            bool seen = false;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) seen = false;        // wall blocks vision
                else if (grid[i][j] == 2) seen = true;    // guard spotted
                else if (seen) grid[i][j] = 3;            // mark as guarded
            }
        }

        // Step 3️⃣: Right → Left sweep
        for (int i = 0; i < m; i++) {
            bool seen = false;
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 1) seen = false;
                else if (grid[i][j] == 2) seen = true;
                else if (seen) grid[i][j] = 3;
            }
        }

        // Step 4️⃣: Top → Bottom sweep
        for (int j = 0; j < n; j++) {
            bool seen = false;
            for (int i = 0; i < m; i++) {
                if (grid[i][j] == 1) seen = false;
                else if (grid[i][j] == 2) seen = true;
                else if (seen) grid[i][j] = 3;
            }
        }

        // Step 5️⃣: Bottom → Top sweep
        for (int j = 0; j < n; j++) {
            bool seen = false;
            for (int i = m - 1; i >= 0; i--) {
                if (grid[i][j] == 1) seen = false;
                else if (grid[i][j] == 2) seen = true;
                else if (seen) grid[i][j] = 3;
            }
        }

        // Step 6️⃣: Count unguarded empty cells
        int unguarded = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    unguarded++;
            }
        }

        return unguarded;
    }
};
