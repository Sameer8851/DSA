#include <bits/stdc++.h>
using namespace std;

/*
--------------------------------------------------------------
🔥 LeetCode 941 | Valid Mountain Array
Author: Sameer Chaudhary
--------------------------------------------------------------
🧠 Problem:
Given an integer array `arr`, return `true` if and only if it is 
a valid mountain array.

A **mountain array** must:
1️⃣ Have at least 3 elements.  
2️⃣ Strictly increase to a single peak (not plateau).  
3️⃣ Strictly decrease after the peak.  

Formally:
- There exists an index `i` such that  
  `arr[0] < arr[1] < ... < arr[i-1] < arr[i]` and  
  `arr[i] > arr[i+1] > ... > arr[n-1]`.

--------------------------------------------------------------
💡 Example 1:
Input:  arr = [2,1]
Output: false

💡 Example 2:
Input:  arr = [3,5,5]
Output: false

💡 Example 3:
Input:  arr = [0,3,2,1]
Output: true
--------------------------------------------------------------
Constraints:
1 ≤ arr.length ≤ 1e4  
0 ≤ arr[i] ≤ 1e4
--------------------------------------------------------------
*/

/*
--------------------------------------------------------------
🧩 Intuition:
--------------------------------------------------------------
- We first climb strictly upward until the peak.
- Then we must descend strictly downward.
- The array must **increase at least once** and **decrease at least once**,
  and there must be **no equal adjacent elements**.

--------------------------------------------------------------
🧮 Time Complexity:  O(n)
🧮 Space Complexity: O(1)
--------------------------------------------------------------
*/

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return false;

        int i = 0;

        // climb up
        while (i + 1 < n && arr[i] < arr[i + 1])
            i++;

        // peak cannot be first or last
        if (i == 0 || i == n - 1)
            return false;

        // climb down
        while (i + 1 < n && arr[i] > arr[i + 1])
            i++;

        // must reach end if valid mountain
        return i == n - 1;
    }
};
