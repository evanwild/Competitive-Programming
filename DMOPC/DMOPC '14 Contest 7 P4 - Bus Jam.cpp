#include <bits/stdc++.h>
using namespace std;

int N, M, H, ans = 0;
int T[1005];

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> H;

  for (int i = 0; i < N; i++)
    cin >> T[i];

  for (int i = N - 2; i >= 0; i--)
  {
    int diff = T[i + 1] - T[i];

    if (diff > H)
    {
      ans += ceil(double(diff - H) / M);
      T[i] += ceil(double(diff - H) / M) * M;
    }
  } 

  cout << ans << "\n";

  return 0;
}