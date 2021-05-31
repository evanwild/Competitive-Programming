#include <bits/stdc++.h>
using namespace std;
#define PB push_back

int N, X, Y;
unordered_map<int, vector<int>> graph;

bool dfs()
{
  bool visited[1005] = {false};
  stack<int> s;

  s.push(X);
  visited[X] = true;

  while (!s.empty())
  {
    int u = s.top();
    s.pop();

    for(auto &v : graph[u])
    {
      if (v == Y)
        return true;
      if (!visited[v])
      {
        visited[v] = true;
        s.push(v);
      }
    }
  }

  return false;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  while (N--)
  {
    cin >> X >> Y;
    graph[X].PB(Y);
  }

  cin >> X >> Y;

  if (dfs())
    cout << "Tangled\n";
  else
    cout << "Not Tangled\n";

  return 0;
}