#include <bits/stdc++.h>
using namespace std;
#define LL long long

int N;
LL a[3005];
LL dp[3005][3005][2];

LL solve (int l, int r, bool t)
{
  if (l == r)
  {
    return (t? a[l] : -a[l]);
  }
  if (dp[l][r][t] != -1)
  {
    return dp[l][r][t];
  }
  return dp[l][r][t] = (t? 
    max(a[l]+solve(l+1, r, 0), a[r]+solve(l, r-1, 0)) : 
    min(solve(l+1, r, 1)-a[l], solve(l, r-1, 1)-a[r]));
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof dp);

  cin >> N;

  for (int i = 0; i < N; i++)
  {
    cin >> a[i];
  }

  cout << solve(0, N - 1, 1) << "\n";

  return 0;
}