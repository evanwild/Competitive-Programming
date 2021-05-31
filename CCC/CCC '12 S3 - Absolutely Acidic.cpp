#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back

int N, R;
map<int, int> freq;
int big_freq = -1, small_freq = -1;
vector<int> big, small;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  while (N--)
  {
    cin >> R;
    freq[R]++;
  }

  for (auto x : freq)
    if (x.S > big_freq)
      big_freq = x.S;
    else if(x.S > small_freq)
      small_freq = x.S;

  for (auto x : freq)
    if(x.S == big_freq)
      big.PB(x.F);
    else if(x.S == small_freq)
      small.PB(x.F);

  if (big.size() > 1)
    cout << big[big.size() - 1] - big[0] << endl;
  else if (big[big.size() - 1] < small[0])
    cout << small[small.size() - 1] - big[0] << endl;
  else
    cout << big[big.size() - 1] - small[0] << endl;

  return 0;
}