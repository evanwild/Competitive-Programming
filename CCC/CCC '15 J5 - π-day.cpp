#include <iostream>
#include <math.h>

using namespace std;

bool dp[251][251][251] = {false};
int dp_val[251][251][251];

int ways(int n, int k, int last_person) {

    if(dp[n][k][last_person]) return dp_val[n][k][last_person];

    int result;

    if(floor(double(n) / k) > last_person || n == 0 || k == 0) {
        result = 0;
    }else if(n == k || k == 1) {
        result = 1;
    }else {
        result = 0;
        for(int i = 1; i < n; i++) {
            if(i <= last_person) {
                result += ways(n-i, k-1, i);
            }
        }
    }

    dp[n][k][last_person] = true;
    dp_val[n][k][last_person] = result;
    return result;
}

int main() {

    int n, k;
    cin >> n >> k;

    cout << ways(n, k, 100000) << endl;

    return 0;
}