#include <bits/stdc++.h>
using namespace std;

int G, P, x, ans = 0;
set<int> gates;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> G >> P;

  for (int i = G; i >= 1; i--)
    gates.insert(-i);

  while (P--)
  {
    cin >> x;

    auto loc = gates.lower_bound(-x);

    if (loc == gates.end())
      break;
    
    gates.erase(*loc);
    
    ans++;
  }

  cout << ans << "\n";

  return 0;
}