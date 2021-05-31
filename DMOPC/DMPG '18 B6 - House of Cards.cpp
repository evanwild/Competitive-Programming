#include <bits/stdc++.h>
using namespace std;

int cards[2005];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, K;
  cin >> N >> K;

  for(int i = 0; i < N; i++)
    cin >> cards[i];

  sort(cards, cards+N, greater<int>());

  int ans = 1;
  int last = 0;

  for(int i = 1; i < N; i++) {
    if(cards[i] + K <= cards[last]) {
      ans++;
      last = i;
    }
  }

  cout << ans << "\n";

  return 0;
}