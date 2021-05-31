#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int x[100001];
bool dp[100001] = {false};
long long dp_val[100001];

long long max_delish(int i) {
    if(dp[i]) return dp_val[i];
    long long result;
    if(i > n) {
        result = 0;
    }else if(i == n) {
        result = x[i];
    }else {
        result = max(
            x[i] + max_delish(i+k+1),
            max_delish(i+1)
        );
    }
    dp[i] = true;
    dp_val[i] = result;
    return result;
}

int main() {

    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        cin >> x[i];
    }

    cout << max_delish(1) << endl;

    return 0;
}