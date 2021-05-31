#include <bits/stdc++.h>
using namespace std;
#define PB push_back

int x, y;
vector<vector<int>> graph(8);
vector<int> ans;
bool vis[8] = {false};
bool temp_vis[8] = {false};

void solve(int i) {
  if(vis[i])
    return;

  if(temp_vis[i]) {
    cout << "Cannot complete these tasks. Going to bed.\n";
    exit(0);
  }

  temp_vis[i] = true;
  for(auto v : graph[i])
    solve(v);

  temp_vis[i] = false;
  vis[i] = true;
  ans.PB(i);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  while(1) {
    cin >> x >> y;
    if (x + y == 0)
      break;
    graph[x].PB(y);
  }

  graph[1].PB(7);
  graph[1].PB(4);
  graph[2].PB(1);
  graph[3].PB(4);
  graph[3].PB(5);

  for (int i = 7; i >= 1; i--) {
    if (!vis[i])
      solve(i);
  }

  for(int i = ans.size()-1; i >= 0; --i)
    cout << ans[i] << " ";

  return 0;
}