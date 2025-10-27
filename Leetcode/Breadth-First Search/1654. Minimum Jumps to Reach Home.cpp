#include <bits/stdc++.h>
using namespace std;

/*
 * Problem: 1654. Minimum Jumps to Reach Home
 * Link: https://leetcode.com/problems/minimum-jumps-to-reach-home/
 * Difficulty: Medium
 *
 * Description:
 * A bug starts at position 0 and wants to reach home at position x.
 * It can move forward by 'a' units or backward by 'b' units.
 * However:
 *  - It cannot land on any forbidden positions.
 *  - It cannot make two backward jumps in a row.
 *  - It cannot go beyond position 6000 (reasonable upper limit based on constraints).
 *
 * Return the minimum number of jumps to reach home, or -1 if it’s not possible.
 *
 * Approach:
 *  - Use BFS to explore all reachable positions since each move (forward/backward)
 *    has equal cost (1 step).
 *  - Maintain a visited array of [position][backwardFlag] to avoid revisiting
 *    the same state.
 *  - For each position:
 *      • Try moving forward (pos + a)
 *      • Try moving backward (pos - b) only if the last move wasn’t backward.
 *
 * Time Complexity:  O(L) — where L is the search limit (~6000)
 * Space Complexity: O(L)
 */

class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        // Queue stores (position, wasBack, steps)
        queue<tuple<int, int, int>> q;

        // visited[pos][backFlag]: to prevent revisiting same state
        vector<vector<bool>> visited(6000, vector<bool>(2, false));

        // store forbidden positions for O(1) lookup
        unordered_set<int> st(forbidden.begin(), forbidden.end());

        q.push({0, 0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            auto [pos, wasBack, steps] = q.front();
            q.pop();

            // if reached destination
            if (pos == x)
                return steps;

            // forward jump
            int forward = pos + a;
            if (forward < 6000 && !st.count(forward) && !visited[forward][0]) {
                visited[forward][0] = true;
                q.push({forward, 0, steps + 1});
            }

            // backward jump (only if last jump wasn’t backward)
            int backward = pos - b;
            if (wasBack == 0 && backward >= 0 && !st.count(backward) && !visited[backward][1]) {
                visited[backward][1] = true;
                q.push({backward, 1, steps + 1});
            }
        }
        return -1; // unreachable
    }
};
