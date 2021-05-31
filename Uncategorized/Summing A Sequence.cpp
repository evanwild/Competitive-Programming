#include <bits/stdc++.h>
using namespace std;
#define LL long long

int N, a[1000005];
LL dp[1000005];

LL solve(int i)
{
  if (i >= N)
    return 0;
  if (dp[i] != -1)
    return dp[i];
  return dp[i] = max(
    a[i] + solve(i + 2),
    solve(i + 1)
  );
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  memset(dp, -1, sizeof dp);

  cin >> N;

  for (int i = 0; i < N; i++)
    cin >> a[i];
  
  LL ans = solve(0);

  if (ans < 0)
    cout << 0 << "\n";
  else
    cout << ans << "\n";
 
  return 0;
}