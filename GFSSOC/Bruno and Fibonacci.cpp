#include <bits/stdc++.h>
using namespace std;

int N;
char x;
bool fib[501] = {false};

void init_fib()
{
  int a = 1, b = 1;
  for (int i = 0; i < 13; i++)
  {
    fib[b] = true;
    int temp = a;
    a = b;
    b += temp;
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  init_fib();

  cin >> N;

  for (int i = 1; i <= N; i++)
  {
    cin >> x;

    if ((x == 'A' && !fib[i]) || (x != 'A' && fib[i]))
    {
      cout << "Bruno, GO TO SLEEP\n";
      return 0;
    }
  }

  cout << "That's quite the observation!" << endl;

  return 0;
}