#include <iostream>
#include <algorithm>

using namespace std;

int n;
int h[1001];

bool memo[1002][1002] = {false};
int memo_val[1002][1002];

int max_sum(int i, int last) {
    if(memo[i][last]) return memo_val[i][last];

    int result;

    if(i > n) {
        result = 0;
    }else if(h[i] > last) {
        result = max(
            h[i] + max_sum(i+1, h[i]), 
            max_sum(i+1, last)
        );
    }else {
        result = max_sum(i+1, last);
    }

    memo[i][last] = true;
    memo_val[i][last] = result;
    return result;
}

int main() {

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    cout << max_sum(1, 0) << endl;

    return 0;
}