#include <bits/stdc++.h>
using namespace std;

string S;
int tc=10, hashs[2005], pows[2005], dp[2005][2];

int get_hash(int l, int r) {
    return hashs[r] - hashs[l-1] * pows[r-l+1];
}

int solve(int i, bool p) {
    if(i == S.size()) return 0;
    if(dp[i][p] != -1) return dp[i][p];
    int ans = 0;
    if(!p) ans = solve(i+1, 0);
    for(int j = 2; i+j-1 <= S.size(); j += 2)
        if(get_hash(i, i-1+j/2) == get_hash(i+j/2, i+j-1))
            ans = max(ans, solve(i+j, 1) + j);
    return dp[i][p] = ans;
}

void solve_tc() {
    cin >> S;
    for(int i = 1; i <= S.size(); ++i)
        hashs[i] = 131*hashs[i-1] + S[i-1];
    memset(dp, -1, sizeof dp);
    cout << solve(1, 0) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    pows[0] = 1;
    for(int i = 1; i <= 2000; ++i)
        pows[i] = 131*pows[i-1];
    
    while(tc--) {
        solve_tc();
    }
}