#include <bits/stdc++.h>
using namespace std;
#define PB push_back

int N, T;
unordered_map<string, vector<string>> graph;

int solve()
{
  queue<string> q;
  unordered_map<string, bool> visited;
  unordered_map<string, int> dist;

  q.push("home");
  visited["home"] = true;
  dist["home"] = 0;

  while (!q.empty())
  {
    string u = q.front();
    q.pop();

    for (auto v : graph[u])
    {
      if (!visited[v])
      {
        q.push(v);
        visited[v] = true;
        dist[v] = dist[u] + 1;
      }
    }
  }

  return dist["Waterloo GO"];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> T;
  cin.ignore();

  string t;
  while (N--)
  {
    getline(cin, t);
  }

  while (T--)
  {
    getline(cin, t);
    int pos = t.find('-');
    graph[t.substr(0, pos)].PB(t.substr(pos + 1));
    graph[t.substr(pos + 1)].PB(t.substr(0, pos));
  }

  int ans = solve();

  if (ans == 0)
  {
    cout << "RIP ACE" << "\n";
  }
  else
  {
    cout << ans << "\n";
  }

  return 0;
}