#include <bits/stdc++.h>
using namespace std;

int rows, cols;
char grid[45][45] = {false};
int answers[6];

int room_size(int r, int c) {
  if(r > rows || c > cols || r < 1 || c < 1 || grid[r][c] == '#') return 0;
  grid[r][c] = '#';
  return 1 + room_size(r-1, c) + room_size(r+1, c) + room_size(r, c-1) + room_size(r, c+1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> rows >> cols;
    
    char c;
    for(int i = 1; i <= rows; i++)
        for(int j = 1; j <= cols; j++) 
            cin >> grid[i][j];

    for(int i = 1; i <= rows; i++)
        for(int j = 1; j <= cols; j++)
            if(isdigit(grid[i][j])) {
                int room = grid[i][j] - '0';
                answers[room] = room_size(i, j);
            }

    for(int i = 1; i <= 5; i++) {
        cout << answers[i] << endl;
    }

    return 0;
}