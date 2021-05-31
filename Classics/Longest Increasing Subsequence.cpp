#include <bits/stdc++.h>
using namespace std;

int N;
int A[1000005];
vector<int> d;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  d.resize(N + 1, 1000000005);

  for (int i = 0; i < N; i++)
    cin >> A[i];
  
  for (int i = 0; i < N; i++)
    *lower_bound(d.begin(), d.end(), A[i]) = A[i];
  
  for (int i = 0; i <= N; i++)
  {
    if (d[i] == 1000000005)
    {
      cout << i << "\n";
      break;
    }
  }

  return 0;
}