#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;

  int min_x = 1001;
  int max_x = -1001;
  int min_y = 1001;
  int max_y = -1001;

  int X, Y;
  for(int i = 0; i < N; i++) {
    cin >> X >> Y;
    min_x = min(min_x, X);
    max_x = max(max_x, X);
    min_y = min(min_y, Y);
    max_y = max(max_y, Y);
  }

  cout << abs(max_x - min_x) * abs(max_y - min_y) << endl;

  return 0;
}