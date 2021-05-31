#include <bits/stdc++.h>
using namespace std;

int N;
int v[100005], dp[100005];

int solve(int i) {
  if(i >= N)
    return 0;
  if(dp[i] != - 1)
    return dp[i];
  return dp[i] = max(
    solve(i+1),
    solve(i+2)+v[i]
  );
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  memset(dp, -1, sizeof dp);

  cin >> N;

  for(int i = 0; i < N; i++)
    cin >> v[i];

  cout << solve(0) << "\n";

  return 0;
}