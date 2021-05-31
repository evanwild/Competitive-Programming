#include <bits/stdc++.h>

using namespace std;

int M, N;
unordered_map<int, vector<pair<int, int>>> graph;
int grid[1001][1001];
bool vis[1001][1001] = {0};

bool dfs(pair<int, int> loc) {
    if(loc.first == M && loc.second == N)
        return 1;

    vis[loc.first][loc.second] = 1;
    for(auto v : graph[grid[loc.first][loc.second]])
        if(!vis[v.first][v.second])
            if(dfs(v))
                return 1;

    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> M >> N;
    for(int r = 1; r <= M; r++) {
        for(int c = 1; c <= N; c++) {
            cin >> grid[r][c];
            graph[r*c].push_back({r, c});
        }
    }

    if(dfs({1, 1}))
        cout << "yes\n";
    else
        cout << "no\n";
}