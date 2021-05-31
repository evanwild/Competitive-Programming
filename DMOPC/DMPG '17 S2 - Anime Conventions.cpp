#include <bits/stdc++.h>
using namespace std;

int N, Q;
int parent[100005];
char inst;

int f(int z)
{
  if (parent[z] == z)
    return z;
  return f(parent[z]);
}

void u(int x, int y)
{
  int a = f(x);
  int b = f(y);
  if (a != b)
    parent[b] = a;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> Q;

  for (int i = 1; i <= N; i++)
    parent[i] = i;

  int x, y;
  while(Q--)
  {
    cin >> inst >> x >> y;
    if (inst == 'A')
      u(x, y);
    else
      cout << (f(x) == f(y) ? "Y\n" : "N\n");
  }

  return 0;
}