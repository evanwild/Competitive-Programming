#include <bits/stdc++.h>

using namespace std;

int N, dist[1501][1501], dp[1501][1501];

int solve(int l, int r) {
    if(l == N || r == N)
        return 0;
    if(dp[l][r] != -1)
        return dp[l][r];
    int v = max(l, r) + 1;
    return dp[l][r] = min(
        solve(v, r) + dist[v][l],
        solve(l, v) + dist[v][r]
    );
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    memset(dp, -1, sizeof dp);

    cin >> N;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> dist[i][j];
    
    cout << solve(0, 0) << '\n';
}