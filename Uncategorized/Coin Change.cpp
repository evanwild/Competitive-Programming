#include <bits/stdc++.h>
using namespace std;

int x, n;
int coin[10005];
int dp[10005];

int solve(int x) {
  if(x == 0) return 0;
  if(x < 0) return 10005;
  if(dp[x] != -1) return dp[x];
  int ans = 10005;
  for(int i = 0; i < n; i++) {
    ans = min(ans, solve(x-coin[i])+1);
  }
  return dp[x] = ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  memset(dp, -1, sizeof dp);

  cin >> x >> n;

  for(int i = 0; i < n; i++)
    cin >> coin[i];

  cout << solve(x) << "\n";

  return 0;
}