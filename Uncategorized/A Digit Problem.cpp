#include <bits/stdc++.h>
using namespace std;

string k;
int n, a, goal, mod = 1e9 + 7;
int dp[1005][2][1 << 10];

int solve(int i, bool l, int dig) {
    if (i == k.size()) {
        return (dig & goal) == goal;
    }
    if (dp[i][l][dig] != -1) {
        return dp[i][l][dig];
    }
    int lim = (l ? 9 : k[i] - '0');
    int ans = 0;
    for (int d = 0; d <= lim; ++d) {
        ans += solve(i + 1, (l || d < lim), (d == 0 && i != k.size() - 1 && !dig) ? 0 : dig | (1 << d));
        ans %= mod;
    }
    return dp[i][l][dig] = ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    while (n--) {
        cin >> a;
        goal |= (1 << a);
    }
    cin >> k;
    memset(dp, -1, sizeof dp);
    cout << solve(0, 0, 0) << '\n';
}