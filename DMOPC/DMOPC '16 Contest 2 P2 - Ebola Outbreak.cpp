#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int parent[100005];
int people[1000001];

int f(int i)
{
  if(parent[i] == i)
    return i;
  return parent[i] = f(parent[i]);
}

void u(int x, int y)
{
  int a = f(x);
  int b = f(y);
  if(a != b)
    parent[b] = a;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  for (int i = 1; i <= N; i++)
    parent[i] = i;

  for (int i = 0; i < M; i++)
  {
    cin >> K;

    for (int j = 1; j <= K; j++)
      cin >> people[j];

    for (int j = 1; j <= K; j++)
      for (int k = j + 1; k <= K; k++)
        u(people[j], people[k]);
  }

  int ans = 0;
  vector<int> people;

  for (int i = 1; i <= N; i++)
  {
    if (f(1) == f(i))
    {
      ans++;
      people.push_back(i);
    }
  }
  
  cout << ans << "\n";
  for (auto p : people)
    cout << p << " ";
  cout << "\n";
  
  return 0;
}