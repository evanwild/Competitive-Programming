#include <bits/stdc++.h>
using namespace std;

int N, L;
int trains[51];

int solve() {
  int ans = 0;
  bool sorted;
  for(int pass = 0; pass < L; pass++) {
    sorted = true;
    for(int elem = 0; elem < L-pass-1; elem++) {
        if(trains[elem] > trains[elem+1]) {
          sorted = false;
          ans++;
          int temp = trains[elem+1];
          trains[elem+1] = trains[elem];
          trains[elem] = temp;
        }
    }
    if(sorted) 
      return ans;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;

  while(N--) {
    cin >> L;
    for(int i = 0; i < L; i++)
      cin >> trains[i];
    cout << "Optimal train swapping takes " << solve() << " swaps." << endl;
  }

  return 0;
}