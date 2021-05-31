#include <bits/stdc++.h>
using namespace std;

int N, M;
int X[100005], Y[100005];

int f(int l, int r, int x)
{
  if (r >= l)
  {
    int m = (l + r) / 2;

    if (X[m] <= x)
    {
      int z = f(l, m-1, x);
      if (z != -1)
        return z;
      return m;
    }
    return f(m+1, r, x);
  }

  return -1;
}

int solve()
{
  int ans = 0;
  for (int j = M - 1; j >= 0; j--)
  {
    int i = f(0, M-1, Y[j]);
    if (i != -1)
      ans = max(ans, j - i);
  }
  return ans;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  while (N--)
  {
    cin >> M;

    for (int i = 0; i < M; i++)
      cin >> X[i];
    
    for (int i = 0; i < M; i++)
      cin >> Y[i];

    cout << "The maximum distance is " << solve() << "\n";
  }

  return 0;
}