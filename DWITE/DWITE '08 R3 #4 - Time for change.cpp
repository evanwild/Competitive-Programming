#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int m, n;
int coins[15];
int memo[105];

int min_coins(int amount) {
    if(memo[amount] != -1) {
        return memo[amount];
    }
    if(amount == 0) {
        return 0;
    }
    int best = 1000000;
    for(int i = 1; i <= n; i++) {
        if(amount-coins[i] >= 0) {
            best = min(
                best,
                min_coins(amount-coins[i])
            );
        }
    }
    memo[amount] = best+1;
    return best+1;
}

int main() {

    int tests = 5;

    while(tests--) {

        cin >> m >> n;

        for(int i = 1; i <= n; i++) {
            cin >> coins[i];
        }

        memset(memo, -1, sizeof memo);
        cout << min_coins(m) << endl;

    }

    return 0;
}