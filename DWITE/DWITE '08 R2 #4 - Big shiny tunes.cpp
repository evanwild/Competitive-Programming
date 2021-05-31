#include <bits/stdc++.h>
using namespace std;

int S, N;
int dp[21][101];
int space[21], utility[21];
int t = 5;

int solve(int i, int s) {
  if(i > N) return 0;
  if(dp[i][s] != -1) return dp[i][s];
  if(space[i] > s) return dp[i][s] = solve(i+1, s);
  return dp[i][s] = max(solve(i+1, s-space[i]) + utility[i], solve(i+1, s));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while(t--) {
    memset(dp, -1, sizeof dp);

    cin >> S >> N;
    for(int i = 1; i <= N; i++)
      cin >> space[i] >> utility[i];
      
    cout << solve(1, S) << "\n";
  }

  return 0;
}