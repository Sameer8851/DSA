#include <bits/stdc++.h>
using namespace std;

/*
------------------------------------------------------------
🧩 Problem: 2295. Replace Elements in an Array
------------------------------------------------------------
You are given a 0-indexed array `nums` consisting of `n` distinct positive integers.
You must perform `m` replacement operations. In the i-th operation, replace 
`operations[i][0]` with `operations[i][1]`.

It is guaranteed that:
- `operations[i][0]` always exists in `nums`
- `operations[i][1]` does **not** exist in `nums`

Return the array after performing all operations.

------------------------------------------------------------
📘 Example 1:
Input:
nums = [1,2,4,6]
operations = [[1,3],[4,7],[6,1]]

Output:
[3,2,7,1]

Explanation:
1️⃣ Replace 1 → 3 → nums = [3,2,4,6]
2️⃣ Replace 4 → 7 → nums = [3,2,7,6]
3️⃣ Replace 6 → 1 → nums = [3,2,7,1]

------------------------------------------------------------
📘 Example 2:
Input:
nums = [1,2]
operations = [[1,3],[2,1],[3,2]]

Output:
[2,1]

Explanation:
1️⃣ Replace 1 → 3 → nums = [3,2]
2️⃣ Replace 2 → 1 → nums = [3,1]
3️⃣ Replace 3 → 2 → nums = [2,1]
------------------------------------------------------------
🔒 Constraints:
- n == nums.length
- m == operations.length
- 1 <= n, m <= 10⁵
- 1 <= nums[i], operations[i][0], operations[i][1] <= 10⁶
- All values in `nums` are distinct
- For each operation:
  - operations[i][0] exists in nums
  - operations[i][1] does not exist in nums
------------------------------------------------------------
🧠 Intuition:
Instead of modifying `nums` directly (which is O(n) per operation),
we can **track indices using a hash map**:

- Step 1️⃣: Store each number’s index → `mp[num] = index`.
- Step 2️⃣: For every operation `(oldNum, newNum)`:
  - Copy its index to the new number.
  - Erase the old number from the map.
- Step 3️⃣: Reconstruct the final array from the updated map.

------------------------------------------------------------
⚙️ Approach:
- Use `unordered_map<int,int>` for O(1) lookup/update.
- At the end, place each number at its correct index.

------------------------------------------------------------
⏱️ Time Complexity: O(n + m)
📦 Space Complexity: O(n)
------------------------------------------------------------
*/

class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, int> mp;  // number → index mapping

        // Step 1️⃣: Initialize map with initial indices
        for (int i = 0; i < nums.size(); i++)
            mp[nums[i]] = i;

        // Step 2️⃣: Perform replacements
        for (auto& op : operations) {
            int oldNum = op[0];
            int newNum = op[1];
            mp[newNum] = mp[oldNum];  // copy index
            mp.erase(oldNum);         // remove old number
        }

        // Step 3️⃣: Build final array using updated mapping
        vector<int> ans(nums.size());
        for (auto& [num, idx] : mp)
            ans[idx] = num;

        return ans;
    }
};

