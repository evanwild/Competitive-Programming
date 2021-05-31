#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define F first
#define S second

int N, H;
int grid[1505][1505];
bool visited[1505][1505] = {false};

bool solve(int i, int j)
{
  if (i == N && j == N)
  {
    return true;
  }

  if (visited[i][j])
  {
    return false;
  }

  visited[i][j] = true;

  bool dir[4] = {false};

  if (i > 1)
  {
    dir[0] = (abs(grid[i][j] - grid[i - 1][j]) <= H && solve(i - 1, j));
  }
  if (i < N)
  {
    dir[1] = (abs(grid[i][j] - grid[i + 1][j]) <= H && solve(i + 1, j));
  }
  if (j > 1)
  {
    dir[2] = (abs(grid[i][j] - grid[i][j - 1]) <= H && solve(i, j - 1));
  }
  if (j < N)
  {
    dir[3] = (abs(grid[i][j] - grid[i][j + 1]) <= H && solve(i, j + 1));
  }

  return max({dir[0], dir[1], dir[2], dir[3]});
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
    
  cin >> N >> H;

  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= N; j++)
    {
      cin >> grid[i][j];
    }
  }

  bool ans = solve(1, 1);

  cout << (ans ? "yes\n" : "no\n");

  return 0;
}