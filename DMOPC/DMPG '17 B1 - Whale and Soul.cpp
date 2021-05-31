#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define MP make_pair
#define F first
#define S second

int N;
PII options[11];

bool func(const PII& a, const PII& b) {
  if(a.S > b.S) return true;
  else if(a.S == b.S) return (a.F < b.F);
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;

  int c, d;
  for(int i = 0; i < N; i++) {
    cin >> c >> d;
    options[i] = MP(c, d);
  }
  
  sort(options, options+N, func);

  cout << options[0].F << " " << options[0].S << endl;

  return 0;
}