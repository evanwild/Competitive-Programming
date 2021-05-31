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

int n, m;
GRAPH graph;
VPII edges;
int ignore1, ignore2;

bool dfs() {
	
	stack<int> to_visit;
	bool visited[55] = {false};
	
	visited[1] = true;
	to_visit.push(1);
	
	while(!to_visit.empty()) {
		
		int u = to_visit.top();
		to_visit.pop();
	
		for(auto &node : graph[u]) {
			
			if(ignore1 == u && ignore2 == node) {
				continue;
			}
			
			if(node == n) return true;
			if(!visited[node]) {
				visited[node] = true;
				to_visit.push(node);
			}
		}
	}
	
	return false;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	
	int s, t;
	while(m--) {
		cin >> s >> t;
		graph[s].PB(t);
		edges.PB(MP(s, t));
	}
	
	for(auto edge : edges) {
		ignore1 = edge.F;
		ignore2 = edge.S;
		if(dfs()) {
			cout << "YES" << endl;
		}else {
			cout << "NO" << endl;
		}
	}
	
	return 0;
}