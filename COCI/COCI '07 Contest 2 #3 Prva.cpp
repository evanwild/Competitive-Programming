#include <bits/stdc++.h>
using namespace std;

int R, C;
char grid[21][21];

vector<string> words;

bool is_top(int i, int j) {
  if(grid[i][j] == '#') return false;
  if(i == R-1) return false;
  if(i == 0) {
    if(grid[i+1][j] != '#') return true;
    return false;
  }
  if(grid[i-1][j] == '#' && grid[i+1][j] != '#') return true;
  return false;
}

bool is_left(int i, int j) {
  if(grid[i][j] == '#') return false;
  if(j == C-1) return false;
  if(j == 0) {
    if(grid[i][j+1] != '#') return true;
    return false;
  }
  if(grid[i][j-1] == '#' && grid[i][j+1] != '#') return true;
  return false;
}

void get_words() {
  for(int i = 0; i < R; i++) {
    for(int j = 0; j < C; j++) {
      string w;
      if(is_top(i, j)) {
        for(int k = i; k < R; k++) {
          if(grid[k][j] == '#') break;
          w += grid[k][j];
        }
        words.push_back(w);
      }
      w = "";
      if(is_left(i, j)) {
        for(int k = j; k < C; k++) {
          if(grid[i][k] == '#') break;
          w += grid[i][k];
        }
        words.push_back(w);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> R >> C;

  for(int i = 0; i < R; i++)
    for(int j = 0; j < C; j++)
      cin >> grid[i][j];

  get_words();

  sort (words.begin(), words.end());

  cout << words[0] << "\n";

  return 0;
}