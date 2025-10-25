class Solution {
public:
    bool isValid(string& part) {
        if (part.size() > 1 && part[0] == '0')
            return false;
        int num = stoi(part);
        return num >= 0 && num <= 255;
    }
    string joinWithDots(const vector<string>& parts) {
        string ip;
        for (int i = 0; i < parts.size(); ++i) {
            ip += parts[i];
            if (i != parts.size() - 1)
                ip += '.';
        }
        return ip;
    }
    void backtrack(string& s, int start, vector<string>& path,
                   vector<string>& result) {
        if (path.size() == 4) {
            if (start == s.size()) {
                result.push_back(joinWithDots(path));
            }
            return;
        }
        for (int i = 1; i <= 3; i++) {
            if (i + start > s.size())
                break;
            string part = s.substr(start, i);
            if (isValid(part)) {
                path.push_back(part);
                backtrack(s, start + i, path, result);
                path.pop_back();
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> path;
        backtrack(s, 0, path, result);
        return result;
    }
};