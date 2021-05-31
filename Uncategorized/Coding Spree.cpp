#include <bits/stdc++.h>

using namespace std;

int N, T, V[1005], H[1005], dp[1005][1005];

int solve(int i, int t) {
    if(i == N)
        return 0;
    if(dp[i][t] != -1)
        return dp[i][t];
    if(H[i] > t)
        return dp[i][t] = solve(i+1, t);
    return dp[i][t] = max(
        solve(i+1, t),
        solve(i+1, t-H[i]) + V[i]
    );
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    memset(dp, -1, sizeof dp);

    cin >> N >> T;

    for(int i = 0; i < N; i++)
        cin >> V[i] >> H[i];
    
    cout << solve(0, T) << '\n';
}