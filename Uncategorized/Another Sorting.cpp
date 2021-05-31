#include <bits/stdc++.h>
using namespace std;

bool func(const int &a, const int &b) {
  if(a % 10 > b % 10) return true;
  else if(a % 10 == b % 10) return (a < b);
  else return false;
}

int N;
int a[1000001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;

  for(int i = 0; i < N; i++)
    cin >> a[i];
  
  sort(a, a+N, func);

  for(int i = N-1; i >= 0; i--)
    cout << a[i] << " ";
  cout << "\n";

  return 0;
}