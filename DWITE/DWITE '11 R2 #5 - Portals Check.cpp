#include <bits/stdc++.h>
using namespace std;

int N, tc = 5;
char inst;
string a, b;
int parent[100005];

int id = 1;
unordered_map<string, int> get_id;

int f(int i)
{
  if (parent[i] == i)
    return i;
  return parent[i] = f(parent[i]);
}

void u(int a, int b)
{
  int x = f(a);
  int y = f(b);
  if (x != y)
    parent[y] = x;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  while (tc--)
  { 
    for(int i = 1; i <= 100000; i++)
      parent[i] = i;

    cin >> N;

    while(N--)
    {
      cin >> inst >> a >> b;

      if (!get_id.count(a))
      {
        get_id[a] = id;
        id++;
      }
      if (!get_id.count(b))
      {
        get_id[b] = id;
        id++;
      }

      if (inst == 'p')
      {
        u(get_id[a], get_id[b]);
        continue;
      }
      cout << (f(get_id[a]) == f(get_id[b]) ? "connected\n" : "not connected\n");
    }

  }

  return 0;
}