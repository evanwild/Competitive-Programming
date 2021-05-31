#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
#define PB push_back
#define PI pair<int, int>
#define F first
#define S second

int N, M;
char grid[105][105];
int ans[105][105];
bool cant[105][105] = {false};
int start_row, start_col;
map<PI, vector<PI>> graph;

PI end_loc(int i, int j, int src_i, int src_j, int last_i, int last_j, bool first)
{
  int ans_i = i, ans_j = j;

  if (grid[i][j] == 'U')
    ans_i--;
  else if(grid[i][j] == 'D')
    ans_i++;
  else if(grid[i][j] == 'L')
    ans_j--;
  else if(grid[i][j] == 'R')
    ans_j++;

  bool at_src = (ans_i == src_i && ans_j == src_j);
  bool at_last = (ans_i == last_i && ans_j == last_j);

  if (!first && (at_src || at_last))
    return MP(0, 0);

  if (cant[ans_i][ans_j])
    return MP(0, 0);

  if (grid[ans_i][ans_j] == '.')
    return MP(ans_i, ans_j);

  return end_loc(ans_i, ans_j, src_i, src_j, i, j, 0);
}

void make_graph()
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      if ((grid[i][j] == '.' || grid[i][j] == 'S') && !cant[i][j])
      {
        PI u = MP(i, j);

        graph[u].PB(end_loc(i - 1, j, i - 1, j, i - 1, j, 1));
        graph[u].PB(end_loc(i + 1, j, i + 1, j, i + 1, j, 1));
        graph[u].PB(end_loc(i, j - 1, i, j - 1, i, j - 1, 1));
        graph[u].PB(end_loc(i, j + 1, i, j + 1, i, j + 1, 1));
      }
    }
  }
}

void fill_cant()
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      if (grid[i][j] == 'W')
        cant[i][j] = true;
      else if (grid[i][j] == 'C')
      { 
        cant[i][j] = true;
        // block cells up
        for (int k = i-1; k >= 0; k--)
        {
          char y = grid[k][j];
          if (y == 'W')
            break;
          if(y == '.' || y == 'S')
            cant[k][j] = true;
        }
        // block cells down
        for (int k = i+1; k < N; k++)
        {
          char y = grid[k][j];
          if (y == 'W')
            break;
          if(y == '.' || y == 'S')
            cant[k][j] = true;
        }
        // block cells left
        for (int k = j-1; k >= 0; k--)
        {
          char y = grid[i][k];
          if (y == 'W')
            break;
          if(y == '.' || y == 'S')
            cant[i][k] = true;
        }
        // block cells right
        for (int k = j+1; k < M; k++)
        {
          char y = grid[i][k];
          if (y == 'W')
            break;
          if(y == '.' || y == 'S')
            cant[i][k] = true;
        }
      }
    }
  }
}

void bfs()
{
  queue<PI> q;

  q.push(MP(start_row, start_col));
  ans[start_row][start_col] = 0;

  while (!q.empty())
  {
    PI u = q.front();
    q.pop();

    for (auto v : graph[u])
    {
      if (ans[v.F][v.S] == -1)
      {
        q.push(v);
        ans[v.F][v.S] = ans[u.F][u.S] + 1;
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  memset(ans, -1, sizeof ans);

  cin >> N >> M;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      cin >> grid[i][j];

      if (grid[i][j] == 'S')
      {
        start_row = i;
        start_col = j;
      }
    }
  }

  fill_cant();
  make_graph();
  bfs();

  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      if (grid[i][j] == '.')
        cout << ans[i][j] << "\n";

  return 0;
}