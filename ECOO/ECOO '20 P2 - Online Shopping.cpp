#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define PII pair<int, int> // first is price
#define PB push_back
#define MP make_pair

unordered_map<string, vector<PII>> prices;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  cin >> T;

  while(T--)
  {

    prices.clear();

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
      int M;
      cin >> M;
      for (int j = 0; j < M; j++)
      {
        string S;
        int P, Q;
        cin >> S >> P >> Q;

        prices[S].PB(MP(P, Q));
      }
    }

    for (auto &x : prices)
    {
      sort(x.second.begin(), x.second.end());
    }

    int K;
    cin >> K;

    LL ans = 0;

    for (int i = 0; i < K; i++)
    {
      string S;
      int D;
      cin >> S >> D;

      vector<PII> costs = prices[S];

      for(PII option : costs)
      {
        if(D == 0)
        {
          break;
        }

        if(D < option.second)
        {
          ans += option.first * (D);
          D = 0;
        }
        else
        {
          D -= option.second;
          ans += option.first * option.second;
        }
      }
    }

    cout << ans << "\n";

  }

  return 0;
}