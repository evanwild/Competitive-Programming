#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define LL long long
#define VI vector<int>
#define VLL vector<LL>
#define PII pair<int, int>
#define VPII vector<PII>
#define DEBUG(x) cout << #x << ": " << x << endl
#define GRAPH map<int, VI>
#define WEIGHTED_GRAPH map<int, VPII> // First is node, second is weight
#define INF 2147483647
#define endl '\n'

WEIGHTED_GRAPH graph;

VI dijkstra(int start) {
  priority_queue<PII, VPII, greater<PII>> pq;
  VI dist(graph.size(),INF);

  pq.push(MP(0,start));
  dist[start]=0;

  while(!pq.empty()) {
    int u = pq.top().S;
    pq.pop();

    WEIGHTED_GRAPH::iterator i;

    for(const auto &node : graph[u]) {
      int v = node.F;
      int weight = node.S;
      if(dist[v] > dist[u] + weight) {
        dist[v] = dist[u] + weight;
        pq.push(MP(dist[v], v));
      }
    }
  }

  return dist;
}

VI dist_from_melanie, dist_from_washington;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  int a, b, t;
  while(m--) {
    cin >> a >> b >> t;
    graph[a].PB(MP(b, t));
    graph[b].PB(MP(a, t));
  }

  dist_from_melanie = dijkstra(0);
  dist_from_washington = dijkstra(n-1);

  int ans = 0;

  for(int alex = 0; alex <= n-1; alex++)
    ans = max(ans, dist_from_melanie[alex]+dist_from_washington[alex]);

  cout << ans << endl;

  return 0;
}