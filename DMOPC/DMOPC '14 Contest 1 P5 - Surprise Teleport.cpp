#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define MP make_pair
#define F first
#define S second

int R, C, T;
char grid[1002][1002];
int start_r, start_c, end_r, end_c;
bool vis[1002][1002] = {false};
int dist[1002][1002] = {0};

bool is_valid(int r, int c)
{
  return (r >= 0 && r < R && c >= 0 && c < C && !vis[r][c] && grid[r][c] != 'X');
}

vector<PII> changes = {MP(0,1),MP(1,0),MP(-1,0),MP(0,-1)};

int solve(char end)
{
  queue<PII> q;

  vis[start_r][start_c] = true;
  dist[start_r][start_c] = 0;
  q.push(MP(start_r, start_c));

  while (!q.empty())
  {
    PII u = q.front();
    q.pop();

    if (grid[u.F][u.S] == end)
    {
      return dist[u.F][u.S];
    }

    for (auto &change : changes)
    {
      if(is_valid(u.F + change.F, u.S + change.S))
      {
        vis[u.F + change.F][u.S + change.S] = true;
        dist[u.F + change.F][u.S + change.S] = dist[u.F][u.S] + 1;
        q.push(MP(u.F + change.F, u.S + change.S));
      }
    }
  }

  return 0;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> R >> C >> start_r >> start_c >> end_r >> end_c;

  for (int i = 0; i < R; i++)
  {
    for (int j = 0; j < C; j++)
    {
      cin >> grid[i][j];
    }
  }

  grid[end_r][end_c] = 'E';

  cin >> T;
  for (int i = 0, x, y; i < T; i++)
  {
    cin >> x >> y;
    grid[x][y] = 'T';
  }

  int to_end = solve('E');
  memset(vis, 0, sizeof vis);
  memset(dist, 0, sizeof dist);
  int to_tele = solve('T');

  cout << max(to_end - to_tele, 0) << "\n";

  return 0;
}