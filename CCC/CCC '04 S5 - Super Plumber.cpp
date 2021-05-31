#include <cstdio>
#include <string.h>
#include <algorithm>

using namespace std;

int m, n;
char grid[101][101];
bool memo[101][101][2][2];
int val[101][101][2][2];

int value(const char &c) {
    return (c == '.' || c == '*') ? 0 : c-'0';
}

int max_val(int row, int col, bool up, bool down) {

    if(row<1||row>m||col<1||col>n||grid[row][col]=='*') {
        return -1000000000;
    }

    if(memo[row][col][up][down]) {
        return val[row][col][up][down];
    }

    if(row == m && col == n) {
        return value(grid[row][col]);
    }

    int best = max_val(row, col+1, 1, 1);
    if(down) best = max(best, max_val(row+1, col, 0, 1));
    if(up) best = max(best, max_val(row-1, col, 1, 0));

    memo[row][col][up][down] = true;
    val[row][col][up][down] = value(grid[row][col])+best;
    return val[row][col][up][down];
}

int main() {

    while(true) {
        memset(memo, false, sizeof(memo));
    
        scanf("%i%i", &m, &n);

        if(m == 0 && n == 0) {
            break;
        }

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                scanf(" %c", &grid[i][j]);
            }
        }

        printf("%i\n", max_val(m, 1, 1, 0));
    }

    return 0;
}