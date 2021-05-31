#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int c, m;
int n[1005], k[1005];
int dp[1005][1005];

int solve(int i, int mins) {
    if(dp[i][mins]!=-1) return dp[i][mins];
    if(i > c || mins == 0) return 0;
    if(k[i]>mins) return solve(i+1,mins);
    return dp[i][mins] = max(
        solve(i+1,mins),
        solve(i+1,mins-k[i])+n[i]
    );
}

int main() {

    cin >> c >> m;

    for(int i = 1; i <= c; i++) {
        cin >> n[i] >> k[i];
    }

    memset(dp, -1, sizeof dp);
    cout << solve(1, m) << endl;

    return 0;
}