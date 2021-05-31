#include <bits/stdc++.h>
using namespace std;
#define PB push_back

int N;
char X, S;
string _;
set<char> nodes;
vector<char> ans;
unordered_map<char, vector<char>> graph;

void bfs(char start)
{
  ans.clear();
  set<char> seen;
  queue<char> q;
  seen.insert(start);
  q.push(start);
  while (!q.empty())
  {
    char u = q.front();
    q.pop();
    for (auto v : graph[u])
    {
      if (seen.find(v) == seen.end())
      {
        seen.insert(v);
        q.push(v);
        if (v > 90)
          ans.PB(v);
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  while (N--)
  {
    cin >> X >> _ >> S;
    graph[X].PB(S);

    if (X <= 90)
      nodes.insert(X);
    if (S <= 90)
      nodes.insert(S);
  }

  for (auto node : nodes)
  {
    bfs(node);
    sort(ans.begin(), ans.end());

    cout << node << " = {";

    if (!ans.empty())
    {
      for (int i = 0; i < ans.size() - 1; i++)
        cout << ans[i] << ",";
      cout << ans[ans.size() - 1];
    }

    cout << "}\n";
  }
 
  return 0;
}