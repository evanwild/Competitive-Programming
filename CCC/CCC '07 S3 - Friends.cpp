#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

map<int, vector<int>> graph;

bool dfs(int start, int end) {
	stack<int> q;
	bool visited[100005] = {false};
	
	visited[start] = true;
	q.push(start);
	
	while(!q.empty()) {
		int u = q.top();
		q.pop();
		
		for(auto &node : graph[u]) {
			if(node == end) {
				return true;
			}
			
			if(!visited[node]) {
				visited[node] = true;
				q.push(node);
			}
		}
	}
	
	return false;
}

int dist(int start, int end) {
	queue<int> q;
	bool visited[100005] = {false};
	int dist[100005] = {0};
	
	visited[start] = true;
	dist[0] = 0;
	q.push(start);
	
	while(!q.empty()) {
		int u = q.back();
		q.pop();
		
		for(auto &node : graph[u]) {
			
			if(!visited[node]) {
				visited[node] = true;
				q.push(node);
				dist[node] = dist[u] + 1;
			}
		}
	}
	return dist[end];
}

int main() {	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
		
	int x, y;
	while(n--) {
		cin >> x >> y;
		graph[x].push_back(y);
	}
		
	while(true) {
		cin >> x >> y;
		if(x == 0 && y == 0) break;
		if(dfs(x, y) && dfs(y, x)) {
			cout << "Yes " << dist(x, y)-1 << endl;
		}else {
			cout << "No" << endl;
		}
	}
		
	return 0;
}