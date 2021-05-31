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

int t, l, w;
char grid[52][52];

int bfs(PII start, PII end) {
  queue<PII> to_visit;
  map<PII, bool> visited;
  map<PII, int> dist;

  visited[start] = true;
  to_visit.push(start);
  dist[start] = 0;

  while(!to_visit.empty()) {
    PII current = to_visit.front();
    to_visit.pop();

    for(int i = current.F-1; i <= current.F+1; i++) {
      for(int j = current.S-1; j <= current.S+1; j++) {
        if(abs(i-current.F) == abs(j-current.S)) continue;
        if(i < 0 || i >= w || j < 0 || j >= l) continue;
        if(grid[i][j] == 'X' || visited[MP(i, j)]) continue;
  
        visited[MP(i, j)] = true;
        to_visit.push(MP(i, j));
        dist[MP(i, j)] = dist[current] + 1;
      } 
    }
  }
  return dist[end] ? dist[end] : 100;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> t;

  PII start, last;

  while(t--) {
    cin >> l >> w;
    for(int i = 0; i < w; i++) {
      for(int j = 0; j < l; j++) {
        cin >> grid[i][j];
        if(grid[i][j] == 'C') start = MP(i, j);
        else if(grid[i][j] == 'W') last = MP(i, j);
      }
    }
    int ans = bfs(start, last);
    if(ans >= 60) {
      cout << "#notworth" << endl;
    }else {
      cout << ans << endl;
    }
  }

  return 0;
}