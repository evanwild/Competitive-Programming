#include <bits/stdc++.h>

using namespace std;

int N, inp, ans, tc=2;
unordered_map<int, vector<int>> graph(100005);
bool seen[100005];

void dfs(int i) {
    seen[i] = true;
    for(auto v : graph[i])
        if(!seen[v])
            dfs(v);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    while(tc--) {
        memset(seen, 0, sizeof seen);
        graph.clear();
        ans = 0;

        cin >> N;
        for(int i = 1; i <= N; i++) {
            cin >> inp;
            graph[inp].push_back(i);
            graph[i].push_back(inp);
        }
        for(int i = 1; i <= N; i++) {
            if(!seen[i]) {
                ans++;
                dfs(i);
            }
        }
        cout << ans << ' ';
    }
    cout << '\n';
}