#include <bits/stdc++.h>
using namespace std;

vector<int> logs, saws;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N; 
  cin >> N;

  int e;
  for (int i = 0; i < N; i++){
    cin >> e;
    saws.push_back(e);
  }

  int l;
  for (int i = 0; i < N; i++){
    cin >> l;
    logs.push_back(l);
  }

  sort(saws.begin(), saws.end()); // low to high saws
  sort(logs.begin(), logs.end(), greater<int>()); // high to low logs

  long long ans = 0;
  for (int i = 0; i < N; i++)
    ans += logs[i] * saws[i];

  cout << ans << endl;

  return 0;
}