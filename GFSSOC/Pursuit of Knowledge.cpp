#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define VI vector<int>
#define GRAPH unordered_map<int, VI>

int n, m, t, q;
int dist[1001][1001];
GRAPH graph;

void bfs(const int& start) {
  queue<int> to_visit;
  bool visited[1001]={false};

  visited[start] = true;
  to_visit.push(start);
  dist[start][start] = 0;

  while(!to_visit.empty()) {
    int current = to_visit.front();
    to_visit.pop();

    for(const int& node : graph[current]) {
      if(!visited[node]) {
        visited[node] = true;
        to_visit.push(node);
        dist[start][node] = dist[start][current] + 1;
      }
    }
  }
}

int main() {

  memset(dist, -1, sizeof dist);

  scanf("%d%d%d", &n, &m, &t);

  int a, b;
  while(m--) {
    scanf("%d%d", &a, &b);
    graph[a].PB(b);
  }

  for(int i = 1; i <= n; i++)
      bfs(i); 

  int ans;
  scanf("%d", &q);
  while(q--) {
    scanf("%d%d", &a, &b);
    ans = t * (dist[a][b]);
    if(ans < 0)
      printf("Not enough hallways!\n");
    else
      printf("%d\n", ans);
  }

  return 0;
}