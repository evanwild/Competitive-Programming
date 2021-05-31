#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define MP make_pair
#define F first
#define S second

int N;
PII points[101];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;

  int x, y;
  for(int i = 0; i < N; i++) {
    cin >> x >> y;
    points[i] = MP(x, y); 
  }

  int ans = 2e9;

  for(int i = 0; i < N; i++) {
    for(int j = i + 1; j < N; j++) {
      
      int x_diff = abs(points[i].F - points[j].F);
      int y_diff = abs(points[i].S - points[j].S);

      ans = min(
        ans,
        max(x_diff, y_diff)
      );
    }  
  }

  cout << ans*ans << endl;

  return 0;
}