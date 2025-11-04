#include <bits/stdc++.h>
using namespace std;

/*
--------------------------------------------------------------
🔥 LeetCode 621 | Task Scheduler
Author: Sameer Chaudhary
--------------------------------------------------------------
🧠 Problem:
You are given a list of CPU tasks represented by capital letters `A`–`Z` 
and an integer `n` representing the *cooldown period* between 
the same tasks.

Each task takes 1 unit of time to execute, and during cooldown 
you can either execute different tasks or remain idle.

Return the *minimum number of time units* needed to finish all tasks.

--------------------------------------------------------------
💡 Example 1:
Input:
tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation:
One possible schedule:
A → B → idle → A → B → idle → A → B

--------------------------------------------------------------
💡 Example 2:
Input:
tasks = ["A","C","A","B","D","B"], n = 1
Output: 6
Explanation:
No idle time required.

--------------------------------------------------------------
💡 Example 3:
Input:
tasks = ["A","A","A","B","B","B"], n = 3
Output: 10
--------------------------------------------------------------
Constraints:
1 ≤ tasks.length ≤ 1e4  
0 ≤ n ≤ 100
--------------------------------------------------------------
*/

/*
--------------------------------------------------------------
🧩 Intuition:
--------------------------------------------------------------
- The task with the *highest frequency* determines the structure 
  of the schedule.
- Let `maxFreq` be the highest frequency of any task.
- Let `maxCount` be the number of tasks having this same frequency.

We can think of the schedule as blocks:
    (maxFreq - 1) full blocks + last set of most frequent tasks
Each block has a size of (n + 1): `task + n slots`.

So, the minimum time required:
    (maxFreq - 1) * (n + 1) + maxCount

However, if total tasks > calculated blocks, 
we simply need as many slots as tasks.

--------------------------------------------------------------
🧮 Time Complexity:  O(26 + n) ≈ O(1)
🧮 Space Complexity: O(1)
--------------------------------------------------------------
*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        int maxFreq = 0;
        int maxCount = 0;

        // Step 1️⃣: Count frequency of each task
        for (char task : tasks) {
            freq[task - 'A']++;
            maxFreq = max(maxFreq, freq[task - 'A']);
        }

        // Step 2️⃣: Count how many tasks have this max frequency
        for (int f : freq) {
            if (f == maxFreq)
                maxCount++;
        }

        // Step 3️⃣: Compute the minimum time using formula
        int ans = (maxFreq - 1) * (n + 1) + maxCount;

        // Step 4️⃣: Final result is max of total tasks or computed time
        return max<int>(ans, tasks.size());
    }
};
