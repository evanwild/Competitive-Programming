#include <bits/stdc++.h>
using namespace std;
#define PI pair<int, int>
#define PB push_back
#define MP make_pair
#define COST first
#define VAL second

int T, N, B;
vector<vector<PI>> parts(6);
int dp[6][1001][3001];

int solve(int t, int i, int b)
{
  if (t == T + 1)
    return 0;
  if (dp[t][i][b] != -1)
    return dp[t][i][b];

  PI part = parts[t][i];

  if (i == parts[t].size() - 1)
  {
    if (part.COST > b)
      return INT_MIN;
    return dp[t][i][b] = solve(t + 1, 0, b - part.COST) + part.VAL;
  }

  if (part.COST > b)
    return dp[t][i][b] = solve(t, i + 1, b);

  return dp[t][i][b] = max(
    solve(t + 1, 0, b - part.COST) + part.VAL,
    solve(t, i + 1, b)
  );

}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  memset(dp, -1, sizeof dp);

  cin >> T >> N;

  for (int i = 0, c, v, t; i < N; i++)
  {
    cin >> c >> v >> t;
    parts[t].PB(MP(c, v));
  }

  cin >> B;

  int ans = solve(1, 0, B);
  cout << (ans < 0 ? -1 : ans) << "\n";

  return 0;
}