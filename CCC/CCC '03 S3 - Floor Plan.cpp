#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int rows, cols;
bool grid[26][26] = {false};

int room_size(int r, int c) {
  if(r > rows || c > cols || r < 1 || c < 1 || !grid[r][c]) return 0;
  grid[r][c] = false;
  return 1 + room_size(r-1, c) + room_size(r+1, c) + room_size(r, c-1) + room_size(r, c+1);
}

int main() {

  int flooring;
  cin >> flooring >> rows >> cols;

  char c;
  for(int i = 1; i <= rows; i++) {
    for(int j = 1; j <= cols; j++) {
      cin >> c;
      if(c == '.') grid[i][j] = true;
    }
  }

  vector<int> room_sizes;
  for(int i = 1; i <= rows; i++) {
    for(int j = 1; j <= cols; j++) {
      if(grid[i][j]) {
        room_sizes.push_back(room_size(i, j));
      }
    }
  }

  sort(room_sizes.begin(), room_sizes.end());

  int complete_rooms = 0;
  for(int i = room_sizes.size()-1; i >= 0; i--) {
    if(room_sizes.at(i) <= flooring) {
      flooring -= room_sizes.at(i);
      complete_rooms++;
    }else {
      break;
    }
  }

  if(complete_rooms == 1) {
    cout << complete_rooms << " room, ";
  }else {
    cout << complete_rooms << " rooms, ";
  }

  cout << flooring << " square metre(s) left over" << endl;
  
  return 0;
}