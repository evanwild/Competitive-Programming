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
#define GRAPH unordered_map<int, VI>
#define WEIGHTED_GRAPH map<int, VPII> // First is node, second is weight
#define INF 2147483647
#define endl '\n'

GRAPH graph;
char ignore1, ignore2;

bool dfs(char start, char end) {
  stack<char> to_visit;
  unordered_map<char, bool> visited;

  visited[start] = true;
  to_visit.push(start);

  while(!to_visit.empty()) {
    char current = to_visit.top();
    to_visit.pop();

    if(current == end) {
      return true;
    }

    for(const int &node : graph[current]) {

        if(current == ignore1 && node == ignore2) continue;
        if(current == ignore2 && node == ignore1) continue;

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

  bool road[91][91] = {false};

  char x, y;
  while(true) {
    cin >> x >> y;
    if(x == '*' && y == '*') break;
    graph[x].PB(y);
    graph[y].PB(x);
    road[x][y] = true;
    road[y][x] = true;
  }

  int ans = 0;
  for(int i = 65; i <= 90; i++) {
    for(int j = i+1; j <= 90; j++) {
      if(road[i][j] || road[j][i]) {
        ignore1 = char(i);
        ignore2 = char(j);
        if(!dfs('A', 'B')) {
          ans++;
          cout << ignore1 << ignore2 << endl;
        }
      }
    }
  }

  cout << "There are " << ans << " disconnecting roads." << endl;

  return 0;
}