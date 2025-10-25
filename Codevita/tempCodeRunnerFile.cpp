#include <bits/stdc++.h>
using namespace std;

void dfs(int u, int target, vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& allPaths, vector<bool>& visited){
    if(u == target){
        allPaths.push_back(path);
        return;
    }
    for(int v : graph[u]){
        if(!visited[v]){
            visited[v] = true;
            path.push_back(v);
            dfs(v, target, graph, path, allPaths, visited);
            path.pop_back();
            visited[v] = false;
        }
    }
}

int minimumTotalTowns(int N, int M, vector<pair<int,int>>& roads, int start1, int start2, int outpost){
    vector<vector<int>> graph(N+1);
    for (auto edge : roads) {
    int a = edge.first;
    int b = edge.second;
    graph[a].push_back(b);
    graph[b].push_back(a);
}
    vector<vector<int>> paths1,paths2;
    vector<int>path;
    vector<bool> visited(N + 1,false);

    // paths for scout 1
    path = {start1};
    visited[start1] = true;
    dfs(start1,outpost,graph,path,paths1,visited);
    visited[start1] = false;

    // paths for scout 2
    path = {start2};
    visited[start2] = true;
    dfs(start2, outpost, graph, path, paths2, visited);
    visited[start2] = false;

    int ans = INT_MAX;
    for(auto& p1 : paths1){
        for(auto& p2 : paths2){
            unordered_set<int> towns(p1.begin(),p1.end());
            bool valid = true;

            for(int t : p2){
                if(towns.count(t) && t != outpost){
                    valid = false; // overlap before outpost
                    break;
                }
                towns.insert(t);
            }
            if(valid) ans = min(ans,(int)towns.size());
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