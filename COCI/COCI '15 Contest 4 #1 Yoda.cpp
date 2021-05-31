#include <bits/stdc++.h>
using namespace std;

void solve(const string &smaller, const string &larger, bool x) {
  string ans;

  if(x) {
    for(int i = 0; i < smaller.size(); i++)
      if(larger[i] - '0' >= smaller[i] - '0')
        ans = larger[i] + ans;
    for(int i = smaller.size(); i < larger.size(); i++)
      ans = larger[i] + ans;
  }else {
    for(int i = 0; i < smaller.size(); i++)
      if(smaller[i] - '0' >= larger[i] - '0')
        ans = smaller[i] + ans;
  }

  if(ans == "") cout << "YODA" << endl;
  else cout << stoi(ans) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  string N, M;
  cin >> N >> M;

  reverse(N.begin(), N.end());
  reverse(M.begin(), M.end());

  if(N.size() > M.size()) { solve(M, N, 1); solve(M, N, 0); }
  else { solve(N, M, 0); solve(N, M, 1); }

  return 0;
}