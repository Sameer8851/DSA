#include <bits/stdc++.h>
using namespace std;

int n, start1, start2, outpost;
vector<int> adj[65]; // assuming n <= 60 for bitmasking
int minTowns;
map<string, bool> memo;

void dfs(int curr1, int curr2, long long mask1, long long mask2) {
    string state = to_string(curr1) + "," + to_string(curr2) + "," + 
                   to_string(mask1) + "," + to_string(mask2);
    if (memo.count(state)) return;
    memo[state] = true;

    // Both reached outpost
    if (curr1 == outpost && curr2 == outpost) {
        int count = __builtin_popcountll(mask1) + __builtin_popcountll(mask2) - 1;
        minTowns = min(minTowns, count);
        return;
    }

    // Pruning
    int currentCount = __builtin_popcountll(mask1) + __builtin_popcountll(mask2);
    if (currentCount >= minTowns) return;

    // Scout 1 at outpost, scout 2 continues
    if (curr1 == outpost) {
        for (int next : adj[curr2]) {
            if (!(mask2 & (1LL << next))) {
                dfs(curr1, next, mask1, mask2 | (1LL << next));
            }
        }
        return;
    }

    // Scout 2 at outpost, scout 1 continues
    if (curr2 == outpost) {
        for (int next : adj[curr1]) {
            if (!(mask1 & (1LL << next))) {
                dfs(next, curr2, mask1 | (1LL << next), mask2);
            }
        }
        return;
    }

    // Both scouts moving
    for (int next1 : adj[curr1]) {
        if (!(mask1 & (1LL << next1))) {
            long long newMask1 = mask1 | (1LL << next1);
            for (int next2 : adj[curr2]) {
                if (!(mask2 & (1LL << next2))) {
                    // Paths cannot intersect outside outpost
                    if (next1 == next2 && next1 != outpost) continue;
                    long long newMask2 = mask2 | (1LL << next2);
                    dfs(next1, next2, newMask1, newMask2);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cin >> start1 >> start2 >> outpost;

    minTowns = INT_MAX;

    long long mask1 = 1LL << start1;
    long long mask2 = 1LL << start2;

    if (start1 != start2 || start1 == outpost) {
        dfs(start1, start2, mask1, mask2);
    }

    if (minTowns == INT_MAX) {
        cout << "Impossible\n";
    } else {
        cout << minTowns << "\n";
    }

    return 0;
}
