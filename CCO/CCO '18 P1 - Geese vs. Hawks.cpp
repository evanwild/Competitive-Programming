#include <bits/stdc++.h>
using namespace std;

int N;
string S, T;
int A[1002], B[1002];

int dp[1002][1002];

int solve(int i, int j) {

  if(i == N || j == N) return 0;
  if(dp[i][j] != -1) return dp[i][j];

  int ans = 0;

  if(S[i] == 'W' && T[j] == 'L')
    if(A[i] > B[j])
      ans = max(ans, solve(i+1, j+1) + A[i] + B[j]);

  if(S[i] == 'L' && T[j] == 'W')
    if(A[i] < B[j])
      ans = max(ans, solve(i+1, j+1) + A[i] + B[j]);
    
  return dp[i][j] = max({ans, solve(i+1, j), solve(i, j+1)});
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  memset(dp, -1, sizeof dp);

  cin >> N;
  
  cin >> S;
  for(int i = 0; i < N; i++)
    cin >> A[i];

  cin >> T;
  for(int i = 0; i < N; i++)
    cin >> B[i];

  cout << solve(0, 0) << endl;

  return 0;
}