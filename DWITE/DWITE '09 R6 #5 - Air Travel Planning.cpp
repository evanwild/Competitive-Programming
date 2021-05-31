#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define LL long long
#define VI vector<int>
#define VVI vector<VI>
#define VLL vector<LL>
#define PIS pair<int, string>
#define VPIS vector<PIS>
#define DEBUG(x) cout << #x << ": " << x << endl
#define GRAPH map<int, VI>
#define WEIGHTED_GRAPH map<string, VPIS> // First is node, second is weight
#define INF 2147483647
#define endl '\n'
#define all(x) x.begin(), x.end()

WEIGHTED_GRAPH graph;

int dijkstra() {
  priority_queue<PIS, VPIS, greater<PIS>> pq;
	map<string, int> dist;
	unordered_set<string> visited;

  pq.push(MP(0,"YYZ"));
  dist["YYZ"]=0;
	visited.insert("YYZ");

  while(!pq.empty()) {
    string u = pq.top().S;
    pq.pop();

		if(visited.find(u) == visited.end()) {
			dist[u] = INF;
			visited.insert(u);
		}

    for(const auto &node : graph[u]) {
      string v = node.S;
      int weight = node.F;

			if(visited.find(v) == visited.end()) {
				dist[v] = INF;
				visited.insert(v);
			}

      if(dist[v] > dist[u] + weight) {
        dist[v] = dist[u] + weight;
        pq.push(MP(dist[v], v));
      }
    }
  }

  return dist["SEA"];
}

int tc = 5;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while(tc--) {

		graph.clear();

		int n;
		cin >> n;

		string code1, code2;
		int price;
		while(n--) {
			cin >> code1 >> code2 >> price;
			graph[code1].PB(MP(price, code2));
		}

		cout << dijkstra() << endl;

	}

	return 0;
}