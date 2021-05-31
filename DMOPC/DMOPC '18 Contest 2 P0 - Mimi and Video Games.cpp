#include <bits/stdc++.h>
using namespace std;
#define LL long long

LL N, a, R;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N >> a >> R;

  cout << (R / a <= N ? R / a : N) << "\n";

  return 0;
}