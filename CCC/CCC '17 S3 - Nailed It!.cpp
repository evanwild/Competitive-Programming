#include <bits/stdc++.h>
using namespace std;

int N;
int freq[2005] = {0};
int sums[4010] = {0};
int len = INT_MIN, num;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for (int i = 0, l; i < N; i++)
  {
    cin >> l;
    freq[l]++;
  }

  for (int i = 1; i <= 2000; i++)
  {
    if (freq[i])
    {
      for (int j = i; j <= 2000; j++)
      {
        if(i == j)
          sums[i + j] += freq[i] / 2;
        else if (freq[j])
          sums[i + j] += min(freq[i], freq[j]);
      }
    }
  }
    
  for (int i = 1; i <= 4000; i++)
  {
    if(sums[i] > len)
    {
      len = sums[i];
      num = 1;
    }
    else if (sums[i] == len)
    {
      num++;
    }
  }

  cout << len << " " << num << endl;

  return 0;
}