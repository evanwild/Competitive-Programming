#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

const int INF = 1e9+5;

int main() {
    int n;
    cin >> n;

    vector<int> h(n);

    for(int& x : h) {
        cin >> x;
    }

    vector<int> dp(n, INF);
    dp[0] = 0;

    for(int i = 0; i < n; i++) {
        if(i+1 < n)
            dp[i+1] = min(dp[i+1], dp[i] + abs(h[i]-h[i+1]));
        if(i+2 < n)
            dp[i+2] = min(dp[i+2], dp[i] + abs(h[i]-h[i+2]));
    }

    cout << dp[n-1] << endl;

    return 0;
}