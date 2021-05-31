#include <bits/stdc++.h>
using namespace std;
#define PI pair<int, int>
#define MP make_pair
#define F first
#define S second

int N;
PI A[2005];

bool f(PI x, int l=0, int r=N-1)
{
  if (r >= l)
  {
    int m = (l + r) / 2;
    if (A[m] == x)
      return true;
    if (A[m] > x)
      return f(x, l, m - 1);
    return f(x, m + 1, r);
  }
  return false;
}


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for (int i = 0, x, y; i < N; i++)
  {
    cin >> x >> y;
    A[i] = MP(x, y);
  }

  sort(A, A + N);
  
  int ans = 0;

  for (int i = 0; i < N; i++)
  {
    for (int j = i + 1; j < N; j++)
    {
      int x1 = A[i].F;
      int x2 = A[j].F;
      int y1 = A[i].S;
      int y2 = A[j].S;

      if (x1 == x2 || y1 == y2)
        continue;

      if (f(MP(x1, y2)) && f(MP(x2, y1)))
      {
        ans = max(ans, abs((y2-y1)*(x2-x1)));
      }
    }
  }

  cout << ans << "\n";

  return 0;
}