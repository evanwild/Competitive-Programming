#include <bits/stdc++.h>
using namespace std;

int N, M;
int ans = 0;
string inp;
set<string> X, Y;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  for (int i = 0; i < N; i++)
  {
    cin >> inp;
    X.insert(inp);
  }

  for (int i = 0; i < M; i++)
  {
    cin >> inp;
    Y.insert(inp);
  } 

  for (auto z : X)
    if (Y.find(z) != Y.end())
      ++ans;

  cout << ans << "\n";

  return 0;
}