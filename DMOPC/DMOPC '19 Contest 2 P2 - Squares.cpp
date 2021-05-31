#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int grid[501][501];
bool dp[501][501] = {false};
int dp_val[501][501];

int minimum_cost(int row, int col) {

    if(dp[row][col]) return dp_val[row][col];

    int result;

    if(row == n && col == m) {
        result = grid[n][m];
    }else {
        if(row == n) {
            result = grid[row][col] + minimum_cost(row, col+1);
        }else if(col == m) {
            result = grid[row][col] + minimum_cost(row+1, col);
        }else {
            result = grid[row][col] + min(minimum_cost(row+1, col), minimum_cost(row, col+1));
        }
    }

    dp[row][col] = true;
    dp_val[row][col] = result;
    return dp_val[row][col];
}

int main() {

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> grid[i][j];
        }
    }

    cout << minimum_cost(1, 1) << endl;

    return 0;
}