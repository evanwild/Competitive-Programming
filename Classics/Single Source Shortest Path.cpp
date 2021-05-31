#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define PI pair<int, int>
#define MP make_pair

int N, M, u, v, w;
vector<vector<PI>> graph;
vector<int> dist;

void dijkstra()
{
  set<PI> pq; // (w, v), sorted by increasing weight.

  dist[1] = 0;
  pq.insert(MP(0, 1));

  while (!pq.empty())
  {
    auto it = pq.begin();
    int u = it->second;
    pq.erase(it);
    
    for (auto &node : graph[u])
    {
      int v = node.first;
      int w = node.second;

      if (dist[v] > dist[u] + w)
      {
        dist[v] = dist[u] + w;
        pq.insert(MP(dist[v], v));
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  graph.resize(N + 1);
  dist.resize(N + 1, 1000000000);

  while (M--)
  {
    cin >> u >> v >> w;
    graph[u].PB(MP(v, w));
    graph[v].PB(MP(u, w));
  }

  dijkstra();

  for (int i = 1; i <= N; i++)
    cout << (dist[i] > 10000000 ? -1 : dist[i]) << "\n";    

  return 0;
}