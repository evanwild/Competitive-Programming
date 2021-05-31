#include <bits/stdc++.h>

using namespace std;

int N, K, h[100005], dp[100005];

int solve(int i) {
    if(i == N)
        return 0;
    if(dp[i] != -1)
        return dp[i];
    int ans = INT_MAX;
    for(int j = i+1; j <= i+K; j++)
        if(j <= N)
            ans = min(ans, solve(j) + abs(h[i] - h[j]));
    return dp[i] = ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    memset(dp, -1, sizeof dp);

    cin >> N >> K;

    for(int i = 1; i <= N; i++)
        cin >> h[i];

    cout << solve(1) << '\n';
}