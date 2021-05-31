#include <bits/stdc++.h>
using namespace std;

int N;
double coins[3005];

bool dp[3005][3005] = {false};
double dp_val[3005][3005];

double solve(int i, int heads) {
  if(i == N) {
    if(heads > N / 2.0)
      return 1;
    return 0;
  }

  if(dp[i][heads]) return dp_val[i][heads];

  dp[i][heads] = true;
  return dp_val[i][heads] = solve(i+1, heads+1) * coins[i] + solve(i+1, heads) * (1.0 - coins[i]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  
  for(int i = 0; i < N; i++)
    cin >> coins[i];

  cout << setprecision(10) << solve(0, 0) << "\n";

  return 0;
}