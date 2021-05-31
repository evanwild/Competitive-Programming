#include <bits/stdc++.h>
using namespace std;

int N, A[100005], B[100005], C[100005], D[100005];
int dp[100005][2][2][2][2];

int solve(int i, bool a, bool b, bool c, bool d)
{
  if(a+b+c+d == min(N, 4))
    return 0;
  if(i == N)
    return INT_MIN;
  if(dp[i][a][b][c][d] != -1)
    return dp[i][a][b][c][d];
  int ans = 0;
  if (!a && A[i] != -1)
    ans = max(ans, solve(i + 1, 1, b, c, d) + A[i]);
  if (!b && B[i] != -1)
    ans = max(ans, solve(i + 1, a, 1, c, d) + B[i]);
  if (!c && C[i] != -1)
    ans = max(ans, solve(i + 1, a, b, 1, d) + C[i]);
  if (!d && D[i] != -1)
    ans = max(ans, solve(i + 1, a, b, c, 1) + D[i]);
  ans = max(ans, solve(i + 1, a, b, c, d));
  return dp[i][a][b][c][d] = ans;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  memset(dp, -1, sizeof dp);

  cin >> N;

  for (int i = 0; i < N; i++)
    cin >> A[i] >> B[i] >> C[i] >> D[i];

  cout << solve(0, 0, 0, 0, 0) << "\n";

  return 0;
}