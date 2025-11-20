#include <bits/stdc++.h>
using namespace std;

/*
--------------------------------------------------------------
🔥 LeetCode 757 | Set Intersection Size At Least Two
Author: Sameer Chaudhary
--------------------------------------------------------------
🧠 Problem:
You are given a 2D array `intervals`, where each interval `intervals[i] = [starti, endi]` represents a range of integers.

Return the *minimum size* of a set `S` such that for every interval `[starti, endi]`,  
there are **at least two elements** in `S` that belong to this interval.

--------------------------------------------------------------
💡 Example 1:
Input:
intervals = [[1,3],[3,7],[4,6],[6,7]]
Output: 5

Explanation:
One possible valid set S = {2, 3, 4, 6, 7}  
Each interval contains at least two elements from S.

💡 Example 2:
Input:
intervals = [[1,2],[2,3],[2,4],[4,5]]
Output: 5
Explanation:
One possible valid set S = {1, 2, 3, 4, 5}

--------------------------------------------------------------
Constraints:
1 ≤ intervals.length ≤ 3 * 10⁴  
intervals[i].length == 2  
0 ≤ starti < endi ≤ 10⁸
--------------------------------------------------------------
*/

/*
--------------------------------------------------------------
🧩 Intuition:
--------------------------------------------------------------
We must ensure that each interval `[l, r]` contains **at least two elements** from the final set.

Key idea:
- Start from the **intervals sorted by start (ascending)** and **end (descending)**.
- Traverse from the **last interval backward**.
- Each interval `intervals[t]` initially requires 2 elements (stored in `todo[t]`).
- For every needed element, we "place" it as far left as possible to benefit previous intervals.

Why sort this way?
➡️ Sorting by start ascending and end descending ensures nested intervals 
   are processed correctly — smaller intervals get priority in coverage.

Algorithm:
1️⃣ Sort intervals as described.
2️⃣ Initialize `todo[i] = 2` for each interval (each needs two hits).
3️⃣ Traverse from rightmost interval to left:
   - Let `[s, e] = intervals[t]`, need `m = todo[t]` elements.
   - Add points `p = s, s+1, ..., s+m-1`.
   - For each added `p`, decrease `todo[i]` for all previous intervals 
     that still require points and where `p ≤ intervals[i][1]`.
4️⃣ Count total points added → final answer.

--------------------------------------------------------------
🧮 Time Complexity:  O(n²)
🧮 Space Complexity: O(n)
--------------------------------------------------------------
*/

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        // Step 1️⃣: Sort intervals
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] != b[0]) return a[0] < b[0];
                 return a[1] > b[1];
             });

        int n = intervals.size();
        vector<int> todo(n, 2); // each interval needs 2 elements
        int ans = 0;

        // Step 2️⃣: Traverse from right to left
        for (int t = n - 1; t >= 0; --t) {
            int s = intervals[t][0];
            int e = intervals[t][1];
            int m = todo[t];  // how many points still needed

            // Step 3️⃣: Place points as far left as possible
            for (int p = s; p < s + m; ++p) {
                for (int i = 0; i <= t; ++i) {
                    if (todo[i] > 0 && p <= intervals[i][1])
                        todo[i]--;  // point covers interval[i]
                }
                ans++;  // count this added point
            }
        }

        return ans;
    }
};
