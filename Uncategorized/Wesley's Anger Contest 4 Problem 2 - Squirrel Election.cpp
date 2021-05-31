#include <bits/stdc++.h>
using namespace std;
#define LL long long

int N;
LL v[5005], p[5005];
int total;

LL dp[5005][5005];

LL solve(int i, int wes)
{
  if(i == N)
  {
    if(wes >= (total % 2 == 0 ? total / 2 + 1 : (total + 1) / 2))
    {
      return 0;
    }
    return 5000000000001;
  }

  if (dp[i][wes] != -1)
  {
    return dp[i][wes];
  }

  return dp[i][wes] = min(
    solve(i + 1, wes + p[i]) + ((v[i] % 2 == 0) ? v[i]/2+1 : (v[i]+1) / 2),
    solve(i + 1, wes)
  );
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  memset(dp, -1, sizeof dp);

  cin >> N;

  for (int i = 0; i < N; i++)
  {
    cin >> v[i] >> p[i];
    total += p[i];
  }

  cout << solve(0, 0) << "\n";

  return 0;
}