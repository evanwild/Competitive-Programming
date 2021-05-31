#include <bits/stdc++.h>
using namespace std;

int N, ans = 0;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  while (N != 1)
  {
    for (int i = 2; i <= N; i++)
    {
      if (N % i == 0)
      {
        int x = N / i;
        N -= x;
        ans += N / x;
        break;
      }
    }
  }

  cout << ans << "\n";

  return 0;
}