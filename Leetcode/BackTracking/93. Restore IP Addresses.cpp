#include <bits/stdc++.h>
using namespace std;

/*
 * Problem: 93. Restore IP Addresses
 * Link: https://leetcode.com/problems/restore-ip-addresses/
 * Difficulty: Medium
 *
 * Description:
 * Given a string s containing only digits, return all possible valid IP addresses
 * that can be obtained by inserting three dots into s.
 *
 * A valid IP address consists of exactly four integers (each between 0 and 255),
 * separated by single dots, and cannot have leading zeros unless the number itself is 0.
 */

class Solution {
public:
    // ✅ Helper function to check if a string part is a valid segment of an IP address.
    bool isValid(string& part) {
        // Leading zeros are not allowed unless the number is 0 itself
        if (part.size() > 1 && part[0] == '0')
            return false;

        int num = stoi(part);
        return num >= 0 && num <= 255;
    }

    // ✅ Join the 4 parts with dots to form a valid IP address string.
    string joinWithDots(const vector<string>& parts) {
        string ip;
        for (int i = 0; i < parts.size(); ++i) {
            ip += parts[i];
            if (i != parts.size() - 1)
                ip += '.';
        }
        return ip;
    }

    // ✅ Recursive backtracking to explore all valid IP segment combinations.
    void backtrack(string& s, int start, vector<string>& path, vector<string>& result) {
        // Base case: if 4 parts are chosen
        if (path.size() == 4) {
            // If we've used all characters, store the valid IP
            if (start == s.size())
                result.push_back(joinWithDots(path));
            return;
        }

        // Explore parts of length 1 to 3
        for (int i = 1; i <= 3; i++) {
            if (start + i > s.size()) break;

            string part = s.substr(start, i);
            if (isValid(part)) {
                path.push_back(part);
                backtrack(s, start + i, path, result);
                path.pop_back(); // backtrack
            }
        }
    }

    // ✅ Main function to return all possible valid IP addresses.
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> path;
        backtrack(s, 0, path, result);
        return result;
    }
};

