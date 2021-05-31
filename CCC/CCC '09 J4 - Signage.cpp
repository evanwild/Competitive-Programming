#include <bits/stdc++.h>
using namespace std;

int w;
vector<string> words = {"WELCOME", "TO", "CCC", "GOOD", "LUCK", "TODAY"};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  cin >> w;
  
  int idx = 0;

  while (idx < 6)
  {
    string curr = "";
    int remaining = w;

    curr += words[idx];
    remaining -= words[idx].size();
    idx++;

    while (idx < 6 && words[idx].size() + 1 <= remaining)
    {
      curr += "." + words[idx];
      remaining -= words[idx].size() + 1;
      idx++;
    }

    if (remaining > 0 && curr.find('.') == string::npos)
    {
      string x(remaining, '.');
      cout << curr + x + "\n";
      continue;
    }

    int last = -1;

    while (remaining > 0)
    {
      int next_dot = curr.find('.', last + 1);

      if (next_dot == string::npos)
      {
        last = -1;
        continue;
      }

      curr.insert(next_dot, ".");
      last = next_dot + 2;
      remaining--;
    }

    cout << curr + "\n";
  }

  return 0;
}