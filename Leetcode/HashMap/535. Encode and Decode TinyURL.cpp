/*
------------------------------------------------------------
💡 Problem: 2125. Number of Laser Beams in a Bank
------------------------------------------------------------
You are given a 0-indexed binary string array `bank` representing 
the floor plan of a bank — an m x n grid.

- `bank[i]` represents the ith row, consisting of '0's and '1's.
- '1' represents a security device, '0' represents an empty cell.

A laser beam connects **two devices** on different rows `r1` and `r2` 
(`r1 < r2`) if and only if **all rows between them have no devices**.

Return the **total number of laser beams** in the bank.

------------------------------------------------------------
📘 Example 1:
Input: bank = ["011001","000000","010100","001000"]
Output: 8

Explanation:
Between each of the following device pairs, there is one beam:
- bank[0][1] -- bank[2][1]
- bank[0][1] -- bank[2][3]
- bank[0][2] -- bank[2][1]
- bank[0][2] -- bank[2][3]
- bank[0][5] -- bank[2][1]
- bank[0][5] -- bank[2][3]
- bank[2][1] -- bank[3][2]
- bank[2][3] -- bank[3][2]

------------------------------------------------------------
📘 Example 2:
Input: bank = ["000","111","000"]
Output: 0

Explanation:
There are no two devices on different rows without devices in between.

------------------------------------------------------------
🔒 Constraints:
- 1 <= m, n <= 500
- bank[i][j] is either '0' or '1'
------------------------------------------------------------
🧠 Intuition:
Each row that has security devices can connect to the **previous row** 
that also had devices. The number of beams formed between two such rows 
is the product of their device counts.

We simply:
1️⃣ Count the number of devices in each row.
2️⃣ Multiply with the previous non-zero device count.
3️⃣ Accumulate the result.

------------------------------------------------------------
⏱️ Time Complexity: O(m * n)
📦 Space Complexity: O(1)
------------------------------------------------------------
*/

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        int prev = 0;  // number of devices in the previous non-empty row

        for (string& row : bank) {
            int curr = 0;

            // Count devices in current row
            for (char c : row) {
                if (c == '1') curr++;
            }

            // If this row has devices, multiply with previous non-empty row
            if (curr > 0) {
                ans += curr * prev;
                prev = curr;
            }
        }
        return ans;
    }
};
