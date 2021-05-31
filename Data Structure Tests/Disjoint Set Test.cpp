#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define PI pair<int, int>
#define F first
#define S second

int N, M;
int parent[100005];
vector<PI> edges;
vector<int> ans;

int f(int i)
{
  if (parent[i] == i)
    return i;
  return parent[i] = f(parent[i]);
}

void u(int x, int y)
{
  parent[x] = parent[y];
}

void kruskal()
{
  for (int i = 0; i < edges.size(); i++)
  {
    int a = f(edges[i].F);
    int b = f(edges[i].S);
    if (a != b)
    {
      ans.PB(i + 1);
      u(a, b);
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  for (int i = 1; i <= N; i++)
    parent[i] = i;

  for (int i = 1, u, v; i <= M; i++)
  {
    cin >> u >> v;
    edges.PB(MP(u, v));
  }

  kruskal();

  if (ans.size() != N - 1)
  {
    cout << "Disconnected Graph\n";
    return 0;
  }

  for (auto e : ans)
    cout << e << "\n";

  return 0;
}