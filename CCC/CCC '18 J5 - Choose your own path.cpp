#include <bits/stdc++.h>
using namespace std;
#define PB push_back

int N, M, v;
vector<vector<int>> graph;
int dist[10005];
int ans2 = -1;

void solve()
{
  bool seen[10005] = {false};
  queue<int> q;

  seen[1] = true;
  dist[1] = 1;
  q.push(1);

  while (!q.empty())
  {
    int u = q.front();
    q.pop();

    if (graph[u].empty() && ans2 == -1)
      ans2 = dist[u];

    for (auto v : graph[u])
    {
      if (!seen[v])
      {
        seen[v] = true;
        dist[v] = dist[u] + 1;
        q.push(v);   
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  memset(dist, -1, sizeof dist);

  cin >> N;
  graph.resize(N + 5);

  for (int u = 1; u <= N; u++)
  {
    cin >> M;
    while(M--)
    {
      cin >> v;
      graph[u].PB(v);
    }
  }

  solve();

  for (int i = 1; i <= N; i++)
  {
    if (dist[i] == -1)
    {
      cout << "N\n" << ans2 << "\n";
      return 0;
    }
  }

  cout << "Y\n" << ans2 << "\n";

  return 0;
}