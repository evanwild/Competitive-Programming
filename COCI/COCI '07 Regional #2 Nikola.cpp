#include <bits/stdc++.h>
using namespace std;

int N;
int dp[1001][1000];
int squares[1001];

int solve(int cloc, int prec)
{
  if (cloc == N)
    return 0;

  if (dp[cloc][prec] != -1)
    return dp[cloc][prec];

  int ans = INT_MAX;

  if (cloc + prec + 1 <= N)
    ans = solve(cloc + prec + 1, prec + 1) + squares[cloc + prec + 1];
  
  if (cloc - prec >= 1)
    ans = min(ans, solve(cloc - prec, prec) + squares[cloc - prec]);

  return dp[cloc][prec] = ans;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof dp);

  cin >> N;

  for (int i = 1; i <= N; i++)
    cin >> squares[i];

  cout << solve(2, 1) + squares[2] << "\n";

  return 0;
}