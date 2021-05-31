#include <bits/stdc++.h>
using namespace std;

int N;
int val[1005];
int dp[1005];

int solve(int n) {
  if(n == 0) return 0;
  if(dp[n] != -1) return dp[n];

  int ans = 0;

  for(int i = 1; i <= N; i++)
    if(n >= i)
      ans = max(ans, solve(n-i)+val[i]);

  return dp[n] = ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  memset(dp, -1, sizeof dp);

  cin >> N;

  for(int i = 1; i <= N; i++)
    cin >> val[i];
  
  cout << solve(N) << endl;

  return 0;
}