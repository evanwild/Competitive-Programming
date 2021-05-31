#include <bits/stdc++.h>
using namespace std;
#define VPII vector<pair<int, int>>
#define PB push_back
#define PI pair<int, int>
#define MP make_pair

int x, y, C, K, z, P_z, D;

unordered_map<int, VPII> graph;
unordered_map<int, int> cost;
vector<int> dist;

void dijkstra() {
  set<PI> pq;
  dist = vector<int>(5001, INT_MAX);

  dist[D] = 0;
  pq.insert(MP(0, D));

  while(!pq.empty()) {
    auto it = pq.begin();
    int u = it->second;
    pq.erase(it);
  
    for(auto &node : graph[u]) {
      int v = node.first;
      int w = node.second;

      if(dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        pq.insert(MP(dist[v], v));
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, T;
  cin >> N >> T;

  while(T--) {
    cin >> x >> y >> C;
    graph[x].PB({y, C});
    graph[y].PB({x, C});
  }

  cin >> K;
  while(K--) {
    cin >> z >> P_z;
    cost[z] = P_z;
  }

  cin >> D;
  dijkstra();

  int ans = INT_MAX;
  for(int i = 1; i <= N; i++)
    if(cost[i])
      ans = min(ans, cost[i] + dist[i]);

  cout << ans << '\n';

  return 0;
}