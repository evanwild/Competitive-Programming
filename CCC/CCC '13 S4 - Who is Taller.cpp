#include <bits/stdc++.h>
using namespace std;

int N, M, x, y, vis[1000005];
vector<vector<int>> graph;

bool dfs(int x, int goal) {
    if (x == goal) return 1;
    if (vis[x]) return 0;
    vis[x] = 1;
    for (auto v : graph[x])
        if (dfs(v, goal)) return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    graph.resize(N + 1);

    while (M--) {
        cin >> x >> y;
        graph[x].push_back(y);
    }

    cin >> x >> y;

    memset(vis, 0, sizeof vis);
    if (dfs(x, y)) {
        cout << "yes\n";
    } else if (dfs(y, x)) {
        memset(vis, 0, sizeof vis);
        cout << "no\n";
    } else {
        cout << "unknown\n";
    }
}