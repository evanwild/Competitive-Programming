#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define GRAPH unordered_map<int, vector<int>>

int N, M;
GRAPH graph;
bool been[10005] = {false};
bool temp_been[10005] = {false};

void dfs(int u)
{
  if (temp_been[u])
  {
    cout << "N\n";
    exit(0);
  }

  temp_been[u] = true;

  for (auto v : graph[u])
  {
    if (!been[v])
    {
      dfs(v);
    }
  }

  temp_been[u] = false;
  been[u] = true;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M;

  for (int i = 0, u, v; i < M; i++)
  {
    cin >> u >> v;
    graph[u].PB(v);
  }

  for (int i = 1; i <= N; i++)
  {
    if (!been[i])
    {
      dfs(i);
    }
  }

  cout << "Y\n";

  return 0;
}