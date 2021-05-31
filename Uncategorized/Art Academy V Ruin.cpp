#include <bits/stdc++.h>

using namespace std;

int N;
string inp;
int x[2005], y[2005];
int dp[2005][2005];

int solve(int h, int a) {
    if(h == N + 1 || a == N + 1) {
        return 0;
    }
    if(dp[h][a] != -1) {
        return dp[h][a];
    }
    int ans;
    if(h > a) {
        ans = min(
            solve(h + 1, a) + abs(y[h + 1] - y[h]) + abs(x[h + 1] - x[h]),
            solve(h, h + 1) + abs(y[h + 1] - y[a]) + abs(x[h + 1] - x[a])
        );
    }else {
        ans = min(
            solve(h, a + 1) + abs(y[a + 1] - y[a]) + abs(x[a + 1] - x[a]),
            solve(a + 1, a) + abs(y[a + 1] - y[h]) + abs(x[a + 1] - x[h])
        );
    }
    return dp[h][a] = ans;
}

int main() {
    memset(dp, -1, sizeof dp);

    cin >> N >> x[0] >> y[0] >> x[1] >> y[1];

    for(int i = 2; i <= N + 1; ++i) {
        cin >> x[i] >> y[i];
    }

    cout << solve(0, 1) << endl;
}