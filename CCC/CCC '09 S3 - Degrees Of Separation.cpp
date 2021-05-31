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
#define PII pair<int, int>
#define VPII vector<PII>
#define DEBUG(x) cout << #x << ": " << x << endl
#define GRAPH map<int, VI>
#define WEIGHTED_GRAPH map<int, VPII> // First is node, second is weight
#define INF 2147483647
#define endl '\n'
#define all(x) x.begin(), x.end()

GRAPH graph;

int bfs(int start, int end) {
	queue<int> to_visit;
	bool visited[55] = {false};
	int dist[55];

	visited[start] = true;
	to_visit.push(start);
	dist[start] = 0;

	while(!to_visit.empty()) {
		int u = to_visit.front();
		to_visit.pop();

		for(auto &node : graph[u]) {
			if(node == end) return dist[u] + 1;
			if(!visited[node]) {
				visited[node] = true;
				to_visit.push(node);
				dist[node] = dist[u] + 1;
			}
		}
	}
	return -1;
}

void edge(int x, int y) {
  graph[x].PB(y);
  graph[y].PB(x);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	edge(1, 6);edge(2, 6);edge(3, 6);edge(4, 6);edge(5, 6);
  edge(3, 5);edge(3, 4);edge(4, 5);edge(6, 7);edge(7, 8);
  edge(8, 9);edge(9, 12);edge(9, 10);edge(10, 11);
  edge(11, 12);edge(3, 15);edge(12, 13);edge(13, 15);
  edge(13, 14);edge(16, 18);edge(16, 17);edge(17, 18);

	char op;
	int x, y;
	while(true) {

		cin >> op;

		if(op == 'q') {
			break;
		}else if(op == 'i') {
			cin >> x >> y;
			if(find(all(graph[x]), y) == graph[x].end()) {
				edge(x, y);
			}
		}else if(op == 'd') {
			cin >> x >> y;
			for(size_t i = 0; i < graph[x].size(); i++) {
				if(graph[x].at(i) == y) {
					graph[x].erase(graph[x].begin()+i);
					break;
				}
			}
		}else if(op == 'n') {
			cin >> x;
			cout << graph[x].size() << endl;
		}else if(op == 'f') {
			cin >> x;
			int ans = 0;
			for(auto fr : graph[x]) {
        for(auto frfr : graph[fr]) {
          if(frfr != x && find(all(graph[x]), frfr) == graph[x].end()) {
            ans++;
          }
        }
			}
			cout << ans << endl;
		}else if(op == 's') {
			cin >> x >> y;
			int ans = bfs(x, y);
			if(ans == -1) {
				cout << "Not connected" << endl;
			}else {
				cout << ans << endl;
			}
		}
	}

	return 0;
}