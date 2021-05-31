#include <bits/stdc++.h>
using namespace std;

int N;
double s[10005];
double dp[10005][3];

double solve(int i, int left)
{
  if (i == N)
  {
    return 0;
  }
  if (dp[i][left] != -1)
  {
    return dp[i][left];
  }
  if (left > 0)
  {
    return solve(i + 1, left - 1) + s[i];
  }
  
  double ans = solve(i + 1, 0) + s[i];

  if (i + 2 < N)
  {
    ans = min(ans, solve(i + 1, 2) + s[i] - min({s[i], s[i + 1], s[i + 2]}));
  }
  if (i + 1 < N)
  {
    ans = min(ans, solve(i + 1, 1) + s[i] - min(s[i], s[i + 1]) / 2.0);
  }

  return dp[i][left] = ans;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  fill_n(&dp[0][0], 10005 * 3, -1.0);

  cin >> N;

  for (int i = 0; i < N; i++)
  {
    cin >> s[i];
  }

  cout << fixed << setprecision(1) << solve(0, 0) << "\n";

  return 0;
}