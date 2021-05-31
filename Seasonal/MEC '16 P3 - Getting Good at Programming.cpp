#include <bits/stdc++.h>
using namespace std;

int N, T;
int dp[105][105][105];

struct Skill {
  int L;
  int x[105];
  int t[105];
} skills[105];

int solve(int i, int l, int t) {
  if(t == 0 || i == N) return 0;

  if(dp[i][l][t] != -1) return dp[i][l][t];

  if(t < skills[i].t[l])
    return dp[i][l][t] = solve(i+1, 0, t);

  if(l > skills[i].L)
    return dp[i][l][t] = solve(i+1, 0, t);

  return dp[i][l][t] = max(
    solve(i, l + 1, t - skills[i].t[l]) + skills[i].x[l],
    solve(i + 1, 0, t)
  );
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  memset(dp, -1, sizeof dp);

  cin >> N >> T;

  for(int i = 0; i < N; i++) {
    cin >> skills[i].L;
    for(int j = 0; j < skills[i].L; j++)
      cin >> skills[i].t[j] >> skills[i].x[j];
  }

  cout << solve(0, 0, T) << "\n";

  return 0;
}