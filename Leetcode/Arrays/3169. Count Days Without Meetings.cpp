#include <bits/stdc++.h>
using namespace std;

/*
--------------------------------------------------------------
🔥 LeetCode 3169 | Count Days Without Meetings
Author: Sameer Chaudhary
--------------------------------------------------------------
🧠 Problem:
You are given:
- An integer `days` — the total number of days.
- A list of meeting intervals `meetings`, where each interval `[l, r]`
  represents a continuous block of days that are busy.

Your task:
Return the **number of days with NO meetings**.

--------------------------------------------------------------
💡 Example 1:
Input:
days = 10
meetings = [[5,7],[1,3],[9,10]]

Sorted intervals → [[1,3],[5,7],[9,10]]
Merged intervals → same (no overlap)

Free days:
(1..3) → before = 0 days  
(3..5) → gap = 1 day  
(7..9) → gap = 1 day  
after 10 → 0 days

Total = 1 + 1 = 2

💡 Example 2:
Input:
days = 5
meetings = [[1,5]]
Merged = [[1,5]]
All days busy → output = 0

--------------------------------------------------------------
Constraints:
1 ≤ days ≤ 10⁹  
1 ≤ meetings.length ≤ 10⁵  
1 ≤ l ≤ r ≤ days
--------------------------------------------------------------
*/

/*
--------------------------------------------------------------
🧩 Intuition:
--------------------------------------------------------------
To count days without meetings:

1️⃣ First merge all overlapping meeting intervals  
   → This ensures we only process disjoint busy segments.

2️⃣ Once merged:
   - Count the gap before the first interval  
   - Count gaps between consecutive intervals  
   - Count gap after the last interval

Example:
merged = [[l1, r1], [l2, r2], ..., [lk, rk]]

Free days =
    (l1 - 1)
  + Σ (li - prev_ri - 1)
  + (days - rk)

We use a standard **interval merge** approach.

--------------------------------------------------------------
🧮 Time Complexity:  O(n log n)   (sorting intervals)
🧮 Space Complexity: O(n)
--------------------------------------------------------------
*/

class Solution {
public:

    // Standard interval merging
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;

        for (int i = 0; i < intervals.size(); i++) {
            // Non-overlapping → add new interval
            if (ans.empty() || ans.back()[1] < intervals[i][0]) {
                ans.push_back(intervals[i]);
            }
            // Overlap → extend last interval
            else {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }

    int countDays(int days, vector<vector<int>>& meetings) {
        vector<vector<int>> merged = merge(meetings);

        long long freeDays = 0;

        // Gap before first interval
        freeDays += merged[0][0] - 1;

        // Gaps between intervals
        for (int i = 0; i < merged.size() - 1; i++) {
            freeDays += merged[i + 1][0] - merged[i][1] - 1;
        }

        // Gap after the last interval
        freeDays += days - merged.back()[1];

        return freeDays;
    }
};
