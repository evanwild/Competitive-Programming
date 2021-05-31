#include <bits/stdc++.h>
using namespace std;

string s;
string alpha = "abcdefghijklmnopqrstuvwxyz";
int dp[51][27];

int lcs(int i, int j) {
  if(i == 0 || j == 0) return 0;
  if(dp[i][j] != -1) return dp[i][j];
  if(s[i-1] == alpha[j-1])
    return dp[i][j] = 1 + lcs(i-1, j-1);
  return dp[i][j] = max(lcs(i-1, j), lcs(i, j-1));
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof dp);

  cin >> s;
  cout << 26 - lcs(s.size(), 26) << endl;

  return 0;
}