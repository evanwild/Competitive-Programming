#include <bits/stdc++.h>
using namespace std;
#define LL long long

int main() {

  int n, k;
  cin >> n >> k;

  LL low = floor(n/double(k)) * k;
  LL high = ceil(n/double(k)) * k;

  if(!low) cout << abs(n-k);
  else cout << min(abs(n-low), abs(n-high));

  return 0;
}