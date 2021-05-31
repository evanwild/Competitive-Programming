#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define LL long long
#define VI vector<int>
#define VLL vector<LL>
#define PII pair<int, int>
#define VPII vector<PII>
#define DEBUG(x) cout << #x << ": " << x << endl
#define GRAPH map<int, VI>
#define WEIGHTED_GRAPH map<int, VPII> // First is node, second is weight
#define INF 2147483647
#define endl '\n'

int n;
int ans = -1;
int grid[1505][1505];
int dp[1505][1505];

int solve(int r, int c) {
  if(r < 0 || r >= n || c < 0 || c >= n) return 0;
  if(dp[r][c] != -1) return dp[r][c];

  int rtnval = 0;
  if(r > 0 && grid[r-1][c] > grid[r][c]) rtnval = max(rtnval, solve(r-1, c));
  if(r < n-1 && grid[r+1][c] > grid[r][c]) rtnval = max(rtnval, solve(r+1, c));
  if(c > 0 && grid[r][c-1] > grid[r][c]) rtnval = max(rtnval, solve(r, c-1));
  if(c < n-1 && grid[r][c+1] > grid[r][c]) rtnval = max(rtnval, solve(r, c+1));
  return dp[r][c] = rtnval+1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  memset(dp, -1, sizeof dp);

  cin >> n;

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cin >> grid[i][j];

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      ans = max(ans, solve(i, j));

  cout << ans-1 << endl;

  return 0;
}