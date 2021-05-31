#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int n, m;
long long a[3005], b[105];
long long dp_val[3005][105][105][2];

long long max_sugar(int a_index, int b_start, int b_end, bool can_take) {
    
    if(dp_val[a_index][b_start][b_end][can_take] != -1) {
        return dp_val[a_index][b_start][b_end][can_take];
    }

    long long result ;

    if(a_index > n && b_start > b_end) {
        result = 0;
    }else if(a_index > n) {
        if(can_take) {
            result = b[b_start]+max_sugar(a_index, b_start+1, b_end, false);
        }else {
            result = max_sugar(a_index, b_start+1, b_end, true);
        }
    }else if(can_take) {
        result = max(
            max_sugar(a_index+1, b_start, b_end, true),
            a[a_index]+max_sugar(a_index+1, b_start, b_end, false)
        );
        if(b_start <= b_end) {
            result = max(
                result,
                b[b_end]+max_sugar(a_index, b_start, b_end-1, false)
            );
        }
    }else {
        result = max_sugar(a_index+1, b_start, b_end, true);
        if(b_start <= b_end) {
            result = max(
                result,
                max_sugar(a_index, b_start+1, b_end, true)
            );
        }
    }

    dp_val[a_index][b_start][b_end][can_take] = result;
    return result;
}

int main() {
    
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    cin >> m;
    for(int i = 1; i <= m; i++) {
        cin >> b[i];
    }

    sort(b+1, b+1+m);

    memset(dp_val, -1, sizeof(dp_val));
    cout << max_sugar(1, 1, m, true) << endl;

    return 0;
}