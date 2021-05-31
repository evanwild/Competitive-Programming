#include <bits/stdc++.h>
using namespace std;

// https://dmoj.ca/user/Josh/solved

bool is_num(string z)
{
  for (char c : z)
    if (!isdigit(c))
      return false;
  return true;
}

string grid[11][10];
int ans[11][10];

int calc_val(string s)
{
  if (is_num(s))
    return stoi(s);

  s += "+";
  int val = 0;

  while (s.find("+") != string::npos)
  {
    string node = s.substr(0, 2);
    s.erase(0, 3);

    int i = node[0] - 65;
    int j = node[1] - '1';

    if (ans[i][j] == -1)
      return -1;

    val += ans[i][j];
  }

  return val;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  memset(ans, -1, sizeof ans);

  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 9; j++)
      cin >> grid[i][j];

  while (1)
  {
    bool change = false;

    for (int i = 0; i < 10; i++)
    {
      for (int j = 0; j < 9; j++)
      {
        int old = ans[i][j];
        ans[i][j] = calc_val(grid[i][j]);

        if (ans[i][j] != old)
          change = true;
      }
    }

    if (!change)  
      break;
  }

  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      if (ans[i][j] == -1)
        cout << "* ";
      else
        cout << ans[i][j] << " ";
    }
    cout << "\n";
  }
    
  return 0;
}