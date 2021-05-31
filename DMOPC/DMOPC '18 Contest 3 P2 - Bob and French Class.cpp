#include <bits/stdc++.h>
using namespace std;
#define LL long long

int n;
LL a[100005], b[100005];
LL dp[100005][3];

LL solve(int i, int consec) {
  if(i == n) return 0;
  if(dp[i][consec] != -1) return dp[i][consec];
  if(consec == 2) return b[i] + solve(i+1, 0);
  return dp[i][consec] = max(
    solve(i+1, consec+1) + a[i],
    solve(i+1, 0) + b[i]
  );
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  memset(dp, -1, sizeof dp);

  cin >> n;

  for(int i = 0; i < n; i++)
    cin >> a[i];

  for(int i = 0; i < n; i++)
    cin >> b[i];

  cout << solve(0, 0) << endl;

  return 0;
}