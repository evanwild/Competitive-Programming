#include <bits/stdc++.h>
using namespace std;
#define PB push_back

int L, n;
string x, y;
unordered_map<string, vector<string>> graph;

int solve()
{
  map<string, int> dist;
  map<string, bool> seen;
  queue<string> q;

  dist[y] = 0;
  seen[y] = true;
  q.push(y);

  while (!q.empty())
  {
    string u = q.front();
    q.pop();
    for (string v : graph[u])
    {
      if (!seen[v])
      {
        dist[v] = dist[u] + 1;
        seen[v] = true;
        q.push(v);
      }
    }
  }

  int ans = -1;
  for (auto d : dist)
    ans = max(ans, d.second);

  return ans;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> L;

  while (L--)
  {
    graph.clear();
    cin >> n;

    for (int i = 0; i < n / 2; i++)
    {
      cin >> x >> y;
      graph[x].PB(y);
      graph[y].PB(x);
    }
    
    cout << n * 10 - solve()*20 << "\n";
  }


  return 0;
}