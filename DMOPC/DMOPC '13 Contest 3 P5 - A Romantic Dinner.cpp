#include <iostream>
#include <algorithm>

using namespace std;

int m, u, r;
int v_list[151], t_list[151], f_list[151]; 
bool dp[301][101][151] = {false};
int dp_val[301][101][151];


int max_value(int m, int u, int r) {
    if(dp[m][u][r]) return dp_val[m][u][r];
    int result;
    if(m <= 0 || u <= 0 || r < 1) {
        result = 0;
    }else if(t_list[r] > m || f_list[r] > u) {
        result = max_value(m, u, r-1);
    }else {
        result = max(
            max_value(m, u, r-1),
            max_value(m-t_list[r], u-f_list[r], r-1)+v_list[r]
        );
    }
    dp[m][u][r] = true;
    dp_val[m][u][r] = result;
    return result;
}

int main() {

    cin >> m >> u >> r;

    for(int i = 1; i <= r; i++) {
        cin >> v_list[i] >> t_list[i] >> f_list[i];
    }

    cout << max_value(m, u, r) << endl;

    return 0;
}