#include <bits/stdc++.h>
using namespace std;

int N, Q;
int a[205];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> Q;

  for (int i = 1; i <= N; i++)
  {
    cin >> a[i];
  }

  int command, l, r;
  for (int i = 0; i < Q; i++)
  {
    cin >> command >> l >> r;

    if(command == 1)
    {
      sort(a + l, a + r + 1);
    }
    else
    {
      sort(a + l, a + r + 1, greater<int>());
    }

  }

  for (int i = 1; i <= N - 1; i++)
  {
    cout << a[i] << " ";
  }
  cout << a[N] << "\n";

  return 0;
}