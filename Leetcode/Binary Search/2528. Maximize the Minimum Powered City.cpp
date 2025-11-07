#include <bits/stdc++.h>
using namespace std;

/*
--------------------------------------------------------------
🔥 LeetCode 2528 | Maximize the Minimum Power
Author: Sameer Chaudhary
--------------------------------------------------------------
🧠 Problem:
You are given:
- An array `stations` where `stations[i]` represents the number of 
  power stations at city `i`.
- Each power station in city `i` provides power to all cities within 
  a radius `r`.
- You can build **at most `k` new power stations** anywhere.

Return the *maximum possible minimum power* across all cities 
after optimally building up to `k` stations.

--------------------------------------------------------------
💡 Example 1:
Input:
stations = [1,2,4,5,0]
r = 1, k = 2
Output: 5

Explanation:
We can build 2 new stations at city indices 1 and 4 to maximize 
the minimum city power.

--------------------------------------------------------------
💡 Example 2:
Input:
stations = [4,4,4,4], r = 0, k = 3
Output: 7
--------------------------------------------------------------
Constraints:
1 ≤ n ≤ 1e5  
0 ≤ stations[i] ≤ 1e5  
0 ≤ r ≤ n - 1  
0 ≤ k ≤ 1e9
--------------------------------------------------------------
*/

/*
--------------------------------------------------------------
🧩 Intuition:
--------------------------------------------------------------
We want to maximize the *minimum power level* achievable across all cities.

💭 Observation:
- Each city’s power = sum of stations within distance `r`.
- Building extra stations increases the power for nearby cities.

⚙️ Approach:
1️⃣ Precompute prefix sums → to calculate initial power of each city.
2️⃣ Use **binary search** on the answer (`minPower`):
    - For each mid value (candidate minPower), check if we can achieve 
      it by adding ≤ `k` stations using a greedy simulation.

3️⃣ The `canAchieve()` function simulates adding stations from left to right:
    - Maintain a sliding window of added power (`windowSum`).
    - If the current city’s power < target, build enough stations at 
      the farthest reachable point (i + r) to satisfy it.

--------------------------------------------------------------
🧮 Time Complexity:  O(n log M)
    where M = possible range of power (≈ 1e14)
🧮 Space Complexity: O(n)
--------------------------------------------------------------
*/

class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<long long> prefix(n + 1, 0);

        // Step 1️⃣: Compute prefix sums
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + stations[i];

        // Step 2️⃣: Compute initial power of each city
        vector<long long> power(n);
        for (int i = 0; i < n; i++) {
            int left = max(0, i - r);
            int right = min(n - 1, i + r);
            power[i] = prefix[right + 1] - prefix[left];
        }

        // Step 3️⃣: Binary search for maximum achievable minimum power
        long long low = 0, high = 1e14, ans = 0;
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (canAchieve(power, r, k, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

private:
    bool canAchieve(vector<long long> power, int r, long long k, long long target) {
        int n = power.size();
        vector<long long> added(n, 0);
        long long used = 0, windowSum = 0;

        // Step 4️⃣: Greedy simulation to verify feasibility
        for (int i = 0; i < n; i++) {
            if (i - r - 1 >= 0) windowSum -= added[i - r - 1];
            if (i + r < n) windowSum += added[i + r];

            long long currPower = power[i] + windowSum;

            if (currPower < target) {
                long long need = target - currPower;
                if (need > k - used) return false;
                used += need;
                added[min(n - 1, i + r)] += need;
                windowSum += need;
            }
        }
        return true;
    }
};
