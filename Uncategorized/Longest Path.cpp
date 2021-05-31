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

int n, m;
GRAPH graph;
int dp[100005];

int solve(int i) {
  if(graph[i].size() == 0) return 0;
  if(dp[i] != -1) return dp[i];
  int ans = -1;
  for(auto node : graph[i]) {
    ans = max(ans, solve(node));
  }
  return dp[i] = ans+1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  memset(dp, -1, sizeof dp);

  cin >> n >> m;

  int x, y;
  while(m--) {
    cin >> x >> y;
    graph[x].PB(y);
  }

  int ans = -1;
  for(int i = 1; i <= n; i++)
    if(solve(i) > ans)
      ans = solve(i);

  cout << ans << endl;

  return 0;
}