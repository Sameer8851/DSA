#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> bfsShortestPaths(int N, vector<vector<int>> &graph, int start, int target)
{
    vector<vector<int>> allPaths;
    queue<vector<int>> q;
    vector<int> visited(N + 1, INT_MAX); // store shortest distance to node

    // push start and mark it 0 in visited
    q.push({start});
    visited[start] = 0;

    int minLength = INT_MAX; // track length of shortest path

    while (!q.empty()) {
        vector<int> path = q.front(); q.pop();
        int u = path.back();

        // if path is already longer than minimal found, skip
        if (path.size() > minLength) continue;

        if (u == target) {
            if (path.size() < minLength) {
                minLength = path.size();
                allPaths.clear(); // discard longer paths found earlier
            }
            allPaths.push_back(path);
            continue;
        }

        for (int v : graph[u]) {
            if (find(path.begin(), path.end(), v) == path.end()) { // simple path
                vector<int> newPath = path;
                newPath.push_back(v);
                q.push(newPath);
            }
        }
    }

    return allPaths;
}


int minimumTotalTowns(int N, int M, vector<pair<int, int>> &roads, int start1, int start2, int outpost) {
    
    // create adj list
    vector<vector<int>> graph(N + 1);
    for (auto edge : roads) {
        int a = edge.first;
        int b = edge.second;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    //sort the adj list
    for (int i = 1; i <= N; i++) sort(graph[i].begin(), graph[i].end());

    // for storing paths for scout1 and scout 2
    vector<vector<int>> paths1 = bfsShortestPaths(N, graph, start1, outpost);
    vector<vector<int>> paths2 = bfsShortestPaths(N, graph, start2, outpost);

    int ans = INT_MAX;
    for (auto &p1 : paths1) { // check every combination of shortest paths to check if possible
        for (auto &p2 : paths2) {
            unordered_set<int> towns(p1.begin(), p1.end());
            bool valid = true;

            for (int t : p2) {
                if (t != outpost && towns.count(t)) { // if t is not equal to outpost and t is in towns means overlap so valid false
                    valid = false;
                    break;
                }
            }
            if (!valid) continue;

            for (int t : p2) towns.insert(t);
            ans = min(ans, (int)towns.size());
        }
    }

    return ans == INT_MAX ? -1 : ans;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int,int>> roads(M);
    for (int i = 0; i < M; i++) {
        cin >> roads[i].first >> roads[i].second;
    }

    int start1, start2, outpost;
    cin >> start1 >> start2;
    cin >> outpost;

    int result = minimumTotalTowns(N, M, roads, start1, start2, outpost);
    if (result == -1) cout << "Impossible\n";
    else cout << result << "\n";

    return 0;
}