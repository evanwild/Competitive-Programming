#include <bits/stdc++.h>

using namespace std;

struct Apple {
    string e;
    int v, a, b, picks = 0;
} a[10];

int N, R, S, dp[10][1002][1002], pick[10][1002][1002];

int solve(int i, int r, int s) {
    if(i == N)
        return 0;
    if(dp[i][r][s] != -1)
        return dp[i][r][s];
    if(r < a[i].a || s < a[i].b)
        return dp[i][r][s] = solve(i+1, r, s);

    int opt1 = solve(i, r-a[i].a, s-a[i].b) + a[i].v;
    int opt2 = solve(i+1, r, s);
    
    pick[i][r][s] = (opt1 > opt2);
    return dp[i][r][s] = max(opt1, opt2);
}

void find_picks(int i, int r, int s) {
    if(i == N)
        return;
    if(pick[i][r][s]) {
        a[i].picks++;
        find_picks(i, r-a[i].a, s-a[i].b);
    }else {
        find_picks(i+1, r, s);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    memset(dp, -1, sizeof dp);

    cin >> N >> R >> S;

    for(int i = 0; i < N; i++)
        cin >> a[i].e >> a[i].v >> a[i].a >> a[i].b;

    cout << solve(0, R, S) << '\n';

    find_picks(0, R, S);
    for(int i = 0; i < N; i++)
        cout << a[i].e << " " << a[i].picks << '\n';
}