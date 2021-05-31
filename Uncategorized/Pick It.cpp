#include <bits/stdc++.h>
using namespace std;

const int mxN = 201;

int n;
int k[mxN];
int dp[mxN][mxN];

int solve(int l, int r)
{
  if (l == r)
    return 0;
  if (dp[l][r] != -1)
    return dp[l][r];
  int ans = 0;
  for (int i = l + 1; i < r; i++)
  {
    ans = max(ans, solve(l, i) + solve(i, r) + k[l] + k[i] + k[r]);
  }
  return dp[l][r] = ans;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  while (1)
  {
    cin >> n;

    if (n == 0)
      break;

    for (int i = 0; i < n; i++)
      cin >> k[i];
    
    memset(dp, -1, sizeof dp);

    cout << solve(0, n - 1) << "\n";
  }

  return 0;
}