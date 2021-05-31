#include <bits/stdc++.h>
using namespace std;

int N, M, D;
int A[1001] = {0};
int tc = 10;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (tc--)
  {
    cin >> N >> M >> D;

    memset(A, 0, sizeof A);
    for (int i = 1, a; i <= M; i++)
    {
      cin >> a;
      A[a]++;
    }

    int ans = 0, dirty = 0;
    for (int i = 1; i <= D; i++)
    {
      if (!N)
      {
        ans++;
        N = dirty;
        dirty = 0;
      }
      N--;
      dirty++;
      N += A[i];
    }

    cout << ans << "\n";
  }

  return 0;
}