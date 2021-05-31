#include <bits/stdc++.h>
using namespace std;

int a[1001], b[1001];

int dp[1001][1001];

int solve(int i, int j) {
  if(i == 0 || j == 0)
    return 0;
  if(dp[i][j] != -1) return dp[i][j];
  if(a[i-1] == b[j-1])
    return dp[i][j] = 1 + solve(i-1, j-1);
  return dp[i][j] = max(solve(i-1, j), solve(i, j-1));
}

int main() {

  memset(dp, -1, sizeof dp);

  int x, y;
  cin >> x >> y;

  for(int i = 0; i < x; i++)
    cin >> a[i];

  for(int i = 0; i < y; i++)
    cin >> b[i];

  cout << solve(x, y) << endl;

  return 0;
}