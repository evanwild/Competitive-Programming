#include <iostream>
#include <algorithm>

using namespace std;

int n;
int triangle[105][105];
bool dp[105][105] = {false};
int dp_val[105][105];

int max_sum(int row, int col) {

    if(dp[row][col]) {
        return dp_val[row][col];
    }

    if(row == n) {
        return triangle[row][col];
    }

    if(col < 1 || col > row) {
        return 0;
    }

    dp[row][col] = true;
    dp_val[row][col] = max(
        max_sum(row+1, col+1),
        max_sum(row+1, col)
    )+triangle[row][col];
    return dp_val[row][col];
}

int main() {

    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cin >> triangle[i][j];
        }
    }

    cout << max_sum(1, 1) << endl;

    return 0;
}