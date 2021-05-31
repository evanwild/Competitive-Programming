#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using pi = pair<int, int>;
#define f first
#define s second
#define mp make_pair

int N, M, K, r, c;

unordered_map<int, unordered_map<int, int>> block;
set<pi> vis;

bool dfs(pi u, int goal_r, int goal_c) {
    if (u.f == goal_r || u.s == goal_c)
        return 1;
    vis.insert(u);
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0)
                continue;
            pi v = u;
            v.f += i;
            v.s += j;
            if (block.count(v.f) && block[v.f].count(v.s))
                if (vis.find(v) == vis.end())
                    if (dfs(v, goal_r, goal_c))
                        return 1;
        }
    }
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M >> K;
    while (K--) {
        cin >> r >> c;
        block[r][c] = 1;
    }

    for (int i = 1; i <= N; i++) {
        if (block.count(i) && block[i].count(1)) {
            if (dfs(mp(i, 1), 1, M)) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    if (block.count(1)) {
        for (int i = 1; i <= M; i++) {
            if (block[1].count(i)) {
                if (dfs(mp(1, i), N, 1)) {
                    cout << "NO\n";
                    return 0;
                }
            }
        }
    }
    if (block.count(N)) {
        for (int i = 1; i <= M; i++) {
            if (block[N].count(i)) {
                if (dfs(mp(N, i), 1, M)) {
                    cout << "NO\n";
                    return 0;
                }
            }
        }
    }
    cout << "YES\n";
}