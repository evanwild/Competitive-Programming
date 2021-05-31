#include <iostream>
#include <climits>

using namespace std;

int h, w;
bool wall[1001][1001] = {false};
bool dp[1001][1001] = {false};
unsigned long long dp_val[1001][1001];

unsigned long long num_ways(int r, int c) {
    if(dp[r][c]) return dp_val[r][c];
    unsigned long long result = 0;
    if(r == h && w == c) result = 1;
    else {
        if(r+1 <= h && !wall[r+1][c]) {
            result += num_ways(r+1, c);
        }
        if(c+1 <= w && !wall[r][c+1]) {
            result += num_ways(r, c+1);
        }
    }
    dp[r][c] = true;
    dp_val[r][c] = result;
    return result%1000000007;
}

int main() {

    cin >> h >> w;

    for(int i = 1; i <= h; i++) {
        for(int j = 1; j <= w; j++) {
            char c;
            cin >> c;
            if(c == '#') {
                wall[i][j] = true;
            }
        }
    }

    cout << num_ways(1, 1) << endl;

    return 0;
}