#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    int n;
    cin >> n;

    vector<int> dp(3);

    for(int i = 0; i < n; i++) {
        vector<int> new_dp(3, 0);
        vector<int> c(3);
        for(int& x : c) {
            cin >> x;
        }
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                if(j != k) {
                    new_dp[k] = max(new_dp[k], dp[j]+c[k]);
                }
            }
        }
        dp = new_dp;
    }

    cout << max({dp[0], dp[1], dp[2]}) << endl;

    return 0;
}