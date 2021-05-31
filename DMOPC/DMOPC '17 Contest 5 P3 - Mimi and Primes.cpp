#include <bits/stdc++.h>
using namespace std;
#define LL long long

int N;
LL A_gcd;
LL ans = 0;

LL gcd(LL x, LL y)
{
  if (y == 0)
    return x;
  return gcd(y, x % y);
}

void solve()
{
  while (A_gcd % 2 == 0)
  {
    ans = 2;
    A_gcd /= 2;
  }

  for (LL i = 3; i * i <= A_gcd; i += 2)
  {
    while (A_gcd % i == 0)
    {
      ans = i;
      A_gcd /= i;
    }
  }

  if (A_gcd > 2)
    ans = A_gcd;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  cin >> A_gcd;

  for (LL i = 1, a; i < N; i++)
  {
    cin >> a;
    A_gcd = gcd(A_gcd, a);
  }

  solve();

  if (ans)
    cout << ans << "\n";
  else
    cout << "DNE\n";

  return 0;
}