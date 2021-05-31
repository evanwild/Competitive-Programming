#include <iostream>

using namespace std;

int r, c;
bool cats[26][26] = {false};
bool dp[26][26] = {false};
int dp_val[26][26];

int ways(int my_r, int my_c) {
    if(dp[my_r][my_c]) {
        return dp_val[my_r][my_c];
    }
    int result = 0;
    if(my_r == r && my_c == c) {
        result = 1;
    }else {
        if(my_r+1 <= r && !cats[my_r+1][my_c]) {
            result += ways(my_r+1, my_c);
        }
        if(my_c+1 <= c && !cats[my_r][my_c+1]) {
            result += ways(my_r, my_c+1);
        }
    }
    dp[my_r][my_c] = true;
    dp_val[my_r][my_c] = result;
    return result;
}

int main() {

    int k;
    cin >> r >> c >> k;

    for(int i = 0; i < k; i++) {
        int row, column;
        cin >> row >> column;
        cats[row][column] = true;
    }

    cout << ways(1, 1) << endl;

    return 0;
}