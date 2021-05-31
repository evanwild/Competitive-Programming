#include <bits/stdc++.h>
using namespace std;

int N;
int est[3][150005];
int dp[150005][3][2][2][2];

int solve(int task, int person, bool s, bool i, bool g) {  
  if(task == N) {
    if(s && i && g) return 0;
  return 10000000;
  }

  if(dp[task][person][s][i][g] != -1) return dp[task][person][s][i][g];
  
  int ans = 10000000;

  if(!s) ans = min(ans, solve(task+1, 0, 1, i, g) + est[0][task]);
  if(!i) ans = min(ans, solve(task+1, 1, s, 1, g) + est[1][task]);
  if(!g) ans = min(ans, solve(task+1, 2, s, i, 1) + est[2][task]);

  return dp[task][person][s][i][g] = min(ans, solve(task+1, person, s, i, g) + est[person][task]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  memset(dp, -1, sizeof dp);

  cin >> N;

  for(int i = 0; i < 3; i++)
    for(int j = 0; j < N; j++)
      cin >> est[i][j];

  cout << min({
    solve(1, 0, 1, 0, 0) + est[0][0],
    solve(1, 1, 0, 1, 0) + est[1][0],
    solve(1, 2, 0, 0, 1) + est[2][0]
  }) << "\n";

  return 0;
}