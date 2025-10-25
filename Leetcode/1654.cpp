class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        queue<tuple<int, int, int>> q; // pos, backFlag, steps
        vector<vector<bool>> visited(6000, vector<bool>(2, false)); // to check if already visited
        unordered_set<int> st(forbidden.begin(), forbidden.end()); // to check if forbidden easily

        q.push({0, 0, 0}); 
        visited[0][0] = true;


        while (!q.empty()) {
            auto [pos, wasBack, steps] = q.front();
            q.pop();

            if (pos == x) return steps; // if reached return steps
            
            // going forward
            int forward = pos + a;
            if (forward < 6000 && !st.count(forward) && !visited[forward][0]) {
                visited[forward][0] = true;
                q.push({forward, 0, steps + 1});
            }
            // going backword
            int backward = pos - b;
            if (wasBack == 0 && backward >= 0 && !st.count(backward) && !visited[backward][1]) {
                visited[backward][1] = true;
                q.push({backward, 1, steps + 1});
            }
        }
        return -1;
    }
};