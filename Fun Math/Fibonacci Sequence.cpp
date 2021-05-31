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
#define all(x) x.begin(), x.end()

unordered_map<unsigned LL, unsigned LL> dp;

unsigned LL solve(unsigned LL n) {
  if(n == 0 || n == 1)
    return 1;
  if(dp[n])
    return dp[n];

  dp[n] = ( solve((n + 1) / 2) * solve(n / 2) + solve((n - 1) / 2) * solve((n - 2) / 2)) % 1000000007;
  return dp[n];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  unsigned LL n;
  cin >> n;

  cout << solve(n-1) << endl;

  return 0;
}