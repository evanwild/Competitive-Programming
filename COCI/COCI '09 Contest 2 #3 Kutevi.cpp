#include <bits/stdc++.h>
using namespace std;

int N, K, opt[10], goal;
bool vis[360] = {0};

bool solve(int u) {
    if (u == goal) return 1;
    vis[u] = 1;
    for (int i = 0; i < N; i++) {
        int v = (u + opt[i]) % 360;
        if (!vis[v])
            if (solve(v)) return 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i < N; i++) cin >> opt[i];

    while (K--) {
        memset(vis, 0, sizeof vis);

        cin >> goal;
        if (solve(0))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}