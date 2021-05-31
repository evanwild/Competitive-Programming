#include <iostream>

using namespace std;

int coins[16];
int dp[16][1000001] = {false};
int dp_val[16][1000001];

int num_ways(int n, int t) {
    if(dp[n][t]) {
        return dp_val[n][t];
    }
    int result;
    if(t == 0) {
        // Reached total.
        result = 1;
    }else if(n == 0) {
        // No coins left.
        result = 0;
    }else if(coins[n] > t) {
        // Coin is more than total, so don't pick and move to next one.
        result = num_ways(n-1, t);
    }else {
        // Calculate ways if you were to use coin or not.
        result = num_ways(n-1, t) + num_ways(n-1, t-coins[n]);
    }
    dp[n][t] = true;
    dp_val[n][t] = result;
    return result;
}

int main() {

    int n, t;
    cin >> n >> t;

    for(int i = 1; i <= n; i++)
        cin >> coins[i];

    cout << num_ways(n, t) << endl;

    return 0;
}