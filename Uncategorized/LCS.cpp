#include <bits/stdc++.h>
using namespace std;

string a, b;

int dp[3001][3001];

string lcs(int x, int y) {
  if(x == 0 || y == 0)
    return "";
  if(a[x-1] == b[y-1])
    return lcs(x-1, y-1) + a[x-1];
  if(dp[x-1][y] > dp[x][y-1])
    return lcs(x-1, y);
  return lcs(x, y-1);
}

int fill_dp(int x, int y) {
  if(x == 0 || y == 0)
    return 0;
  if(dp[x][y] != -1)
    return dp[x][y];
  if(a[x-1] == b[y-1]) {
    return dp[x][y] = fill_dp(x-1, y-1) + 1;
  }
  return dp[x][y] = max(fill_dp(x-1, y), fill_dp(x, y-1));
}

int main() {

  memset(dp, -1, sizeof dp);

  cin >> a >> b;

  fill_dp(a.size(), b.size());

  cout << lcs(a.size(), b.size()) << endl;

  return 0;
}