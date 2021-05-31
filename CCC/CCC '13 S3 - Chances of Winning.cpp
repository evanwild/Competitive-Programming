#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define LL long long
#define VI vector<int>
#define VVI vector<VI>
#define VLL vector<LL>
#define PII pair<int, int>
#define VPII vector<PII>
#define DEBUG(x) cout << #x << ": " << x << endl
#define GRAPH map<int, VI>
#define WEIGHTED_GRAPH map<int, VPII> // First is node, second is weight
#define INF 2147483647
#define endl '\n'
#define all(x) x.begin(), x.end()

int t;

VVI new_scores(VI scores, int a, int b) {
  VVI ans;
  VI scores_copy = scores;

  scores_copy[a] += 3;
  ans.PB(scores_copy);
  scores_copy = scores;
  
  scores_copy[b] += 3;
  ans.PB(scores_copy);
  scores_copy = scores;

  scores_copy[a]++;
  scores_copy[b]++;
  ans.PB(scores_copy);
  scores_copy = scores;

  return ans;
}

int chances_of_winning(VPII games_to_play, VI scores) {
  if(games_to_play.size() == 0) {
    int team_score = scores[t];
    for(int i = 1; i <= 4; i++) {
      if(i == t) continue;
      if(scores[i] >= team_score) return 0;
    }
    return 1;
  }

  PII game = games_to_play.back();
  games_to_play.pop_back();

  VVI possible_scores = new_scores(scores, game.F, game.S);

  int ans = 0;
  for(VI &s : possible_scores) {
    ans += chances_of_winning(games_to_play, s);
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int g;
  cin >> t >> g;

  VI start_score = {-1, 0, 0, 0, 0};

  VPII games_to_play = {MP(1, 2), MP(1, 3), MP(1, 4), MP(2, 3), MP(2, 4), MP(3, 4)};

  int a, b, sa, sb;
  for(int i = 0; i < g; i++) {
    cin >> a >> b >> sa >> sb;
    if(sa > sb) {
      start_score[a] += 3;
    }else if(sb > sa) {
      start_score[b] += 3;
    }else {
      start_score[a]++;
      start_score[b]++;
    }
    for(auto &game : games_to_play) {
      if(game.F == a && game.S == b) {
        games_to_play.erase(find(all(games_to_play), game));
      }
    }
  }

  cout << chances_of_winning(games_to_play, start_score);

  return 0;
}