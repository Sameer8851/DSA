#include <bits/stdc++.h>
using namespace std;

/*
--------------------------------------------------------------
🔥 LeetCode 1578 | Minimum Time to Make Rope Colorful
Author: Sameer Chaudhary
--------------------------------------------------------------
🧠 Problem:
You are given:
- A string `colors` representing the color of each balloon.
- An integer array `neededTime` where `neededTime[i]` is the time
  needed to remove the i-th balloon.

You must remove some balloons so that **no two adjacent balloons**
have the same color. Return the *minimum total time* needed.

--------------------------------------------------------------
💡 Example 1:
Input:
colors = "abaac"
neededTime = [1,2,3,4,5]

Output: 3

Explanation:
Remove the balloons at indices 2 (cost 3) or 1 (cost 2).
Choose the smaller cost, total = 3.

--------------------------------------------------------------
💡 Example 2:
Input:
colors = "abc"
neededTime = [1,2,3]

Output: 0

Explanation:
No adjacent balloons of the same color → no removal needed.

--------------------------------------------------------------
💡 Example 3:
Input:
colors = "aabaa"
neededTime = [1,2,3,4,1]

Output: 2
--------------------------------------------------------------
*/

/*
--------------------------------------------------------------
🧩 Intuition:
--------------------------------------------------------------
- We want to ensure that no two consecutive balloons have
  the same color.
- For every group of consecutive same-color balloons,
  we keep the one with the *maximum time* (costliest),
  and remove the rest (sum of smaller times).

--------------------------------------------------------------
⚙️ Approach:
1️⃣ Iterate through the string using an index `prev` to track
    the last balloon of the current color.
2️⃣ If current color == previous color:
       → Remove the smaller one (add its time to total).
       → Keep the one with the higher neededTime.
3️⃣ Otherwise, just move `prev` to current index.

--------------------------------------------------------------
🧮 Time Complexity:  O(n)
🧮 Space Complexity: O(1)
--------------------------------------------------------------
*/

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int prev = 0;
        int total = 0;

        for (int i = 1; i < n; i++) {
            if (colors[i] == colors[prev]) {
                if (neededTime[i] < neededTime[prev]) {
                    total += neededTime[i];
                } else {
                    total += neededTime[prev];
                    prev = i;
                }
            } else {
                prev = i;
            }
        }

        return total;
    }
};

