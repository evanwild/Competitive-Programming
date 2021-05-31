#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MOD 1000000007

string K;
vector<int> num;
LL dp[100005][2][2][2];

void make_vector()
{
  for (char c : K)
  {
    num.push_back(c - '0');
  }
}

LL solve(int pos, bool less, bool one, bool z)
{
  if (pos == num.size())
  {
    if (one && z)
    {
      return 1;
    }
    return 0;
  }

  if (dp[pos][less][one][z] != -1)
  {
    return dp[pos][less][one][z];
  }

  LL ans = 0;
  int limit = 9;

  if (!less)
  {
    limit = num[pos];
  }

  for (int d = 0; d <= limit; d++)
  {
    bool new_less = less;
    if (!less && d < limit)
    {
      new_less = true;
    }
    
    if(one && z && d == 0)
    {
      continue;
    }

    if (!one && d == 1)
    {
      ans += solve(pos + 1, new_less, 1, 0) % MOD;
    }
    else if (one && d == 0)
    {
      ans += solve(pos + 1, new_less, 1, 1) % MOD;
    }
    else
    {
      ans += solve(pos + 1, new_less, one, z) % MOD;
    }
  }

  return dp[pos][less][one][z] = ans % MOD;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  memset(dp, -1, sizeof dp);

  cin >> K;
  make_vector();

  cout << solve(0, 0, 0, 0) << "\n";

  return 0;
}