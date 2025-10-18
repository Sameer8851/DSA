class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            vector<int> freq(26, 0);
            freq[s[i] - 'a']++;

            for (int j = i + 1; j < s.length(); j++) {
                int maxFreq = 0;
                int minFreq = INT_MAX;
                freq[s[j] - 'a']++;
                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0) {
                        maxFreq = max(maxFreq, freq[k]);
                        minFreq = min(minFreq, freq[k]);
                    }
                }
                if (minFreq != INT_MAX)
                    ans += (maxFreq - minFreq);
            }
        }
        return ans;
    }
};