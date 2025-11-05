#include <bits/stdc++.h>
using namespace std;

/*
--------------------------------------------------------------
🔥 LeetCode | Find X-Sum of All Subarrays of Size K
Author: Sameer Chaudhary
--------------------------------------------------------------
🧠 Problem:
Given an integer array `nums`, and integers `k` and `x`:
For every contiguous subarray of size `k`, compute its **X-Sum** —
the sum of the products (frequency × value) of the top-`x` most
frequent elements in that subarray.

Return an array where each element is the X-Sum of the corresponding
subarray.

--------------------------------------------------------------
💡 Example:
Input:
nums = [1,2,2,3,3,3], k = 4, x = 2

Explanation:
Sliding windows of size 4 → compute top-2 frequency × value sums.

--------------------------------------------------------------
Constraints:
1 ≤ nums.length ≤ 1e5  
1 ≤ nums[i] ≤ 1e5  
1 ≤ k, x ≤ nums.length
--------------------------------------------------------------
*/

/*
--------------------------------------------------------------
🧩 Intuition:
--------------------------------------------------------------
We maintain two ordered multisets:
- `large` → holds the top-`x` (freq, value) pairs contributing
             to the current window’s X-Sum.
- `small` → holds all remaining pairs.

A helper class efficiently handles:
1️⃣ insertion of a number (update frequency),
2️⃣ deletion when it leaves the sliding window,
3️⃣ maintaining running sum of the top-`x` contributions.

For each step:
- Insert current number.
- Remove outgoing number when window > k.
- Record helper.get() when window size == k.

--------------------------------------------------------------
🧮 Time Complexity: O(n log x)
🧮 Space Complexity: O(n)
--------------------------------------------------------------
*/

class Helper {
public:
    explicit Helper(int x) : x(x), result(0) {}

    void insert(int num) {
        if (occ[num]) internalRemove({occ[num], num});
        ++occ[num];
        internalInsert({occ[num], num});
    }

    void remove(int num) {
        internalRemove({occ[num], num});
        --occ[num];
        if (occ[num]) internalInsert({occ[num], num});
    }

    long long get() const { return result; }

private:
    void internalInsert(const pair<int,int>& p) {
        if (large.size() < x || p > *large.begin()) {
            result += 1LL * p.first * p.second;
            large.insert(p);
            if (large.size() > x) {
                auto it = large.begin();
                result -= 1LL * it->first * it->second;
                small.insert(*it);
                large.erase(it);
            }
        } else {
            small.insert(p);
        }
    }

    void internalRemove(const pair<int,int>& p) {
        if (!large.empty() && p >= *large.begin()) {
            result -= 1LL * p.first * p.second;
            large.erase(p);
            if (!small.empty()) {
                auto it = prev(small.end());
                result += 1LL * it->first * it->second;
                large.insert(*it);
                small.erase(it);
            }
        } else {
            small.erase(p);
        }
    }

private:
    int x;
    long long result;
    set<pair<int,int>> large, small;
    unordered_map<int,int> occ;
};

class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        Helper helper(x);
        vector<long long> ans;

        for (int i = 0; i < nums.size(); ++i) {
            helper.insert(nums[i]);
            if (i >= k) helper.remove(nums[i - k]);
            if (i >= k - 1) ans.push_back(helper.get());
        }
        return ans;
    }
};
