#include <bits/stdc++.h>
using namespace std;

int N, X, Y, Z;
int dp[100005];

int solve(int i)
{
  if (i == 0)
    return 0;
  if (dp[i] != -1)
    return dp[i];

  int ans = INT_MIN;

  if (X <= i)
    ans = solve(i - X);
  if (Y <= i)
    ans = max(ans, solve(i - Y));
  if (Z <= i)
    ans = max(ans, solve(i - Z));

  return dp[i] = ans + 1;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof dp);

  cin >> N >> X >> Y >> Z;

  cout << solve(N) << "\n";

  return 0;
}