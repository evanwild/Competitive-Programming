#include <bits/stdc++.h>
using namespace std;

int n;
string a[10001];

bool func(string &a, string &b) {
  return a+b > b+a;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  for(int i = 0; i < n; i++)
    cin >> a[i];

  sort(a, a+n, func);

  for(int i = 0; i < n; i++)
    cout << a[i];

  return 0;
}