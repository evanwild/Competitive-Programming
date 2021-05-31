#include <bits/stdc++.h>
using namespace std;
#define LL long long

char hyphen;
LL maxa, maxb;

bool dp[2002][2002] = {false};
LL dp_val[2002][2002];

LL solve_free(int a, int b) {
  if(a == maxa && b == maxb) return 1;
  if(b >= a) return 0;
  if(dp[a][b]) return dp_val[a][b];

  LL ans = 0;

  if(b < a-1 && b != maxb)
    ans += solve_free(a, b+1);

  if(a != maxa)
    ans += solve_free(a+1, b);

  dp[a][b] = true;
  return dp_val[a][b] = ans % 1000000007;
}

LL solve_ful(int a, int b) {
  if(b == maxb) return 1;
  if(a > b) return 0;
  if(dp[a][b]) return dp_val[a][b];

  LL ans = 0;

  if(a < b)
    ans += solve_ful(a+1, b);

  if(b < maxb)
    ans += solve_ful(a, b+1);

  dp[a][b] = true;
  return dp_val[a][b] = ans % 1000000007;
}

int T;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> T;

  for(int i = 1; i <= T; i++) {

    cin >> maxa >> hyphen >> maxb;

    cout << "Case #" << i << ": ";
    cout << solve_free(1, 0) << " ";
    memset(dp, false, sizeof dp);
    cout << solve_ful(0, 0) << "\n";
    memset(dp, false, sizeof dp);
  }

  return 0;
}