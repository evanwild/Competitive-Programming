#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int n, k, w;
int pins[30001];
int dp[30001][501];

int max_score(int i, int left) {
    if(i > n || left == 0) {
        return 0;
    }else if(dp[i][left]) {
        return dp[i][left];
    }else {
        int result, sum = 0;
        for(int j = i; j < i+w && j <= n; j++) {
            sum += pins[j];
        }

        result = max(
            sum+max_score(i+w, left-1),
            max_score(i+1, left)
        );

        dp[i][left] = result;
        return result;
    }
}

int main() {

    int t;
    cin >> t;

    while(t--) {

        memset(dp, 0, sizeof(dp));
        cin >> n >> k >> w;

        for(int i = 1; i <= n; i++) {
            cin >> pins[i];
        }
    
        cout << max_score(1, k) << endl;
    }

    return 0;
}