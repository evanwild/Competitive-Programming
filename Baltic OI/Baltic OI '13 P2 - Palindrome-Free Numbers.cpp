#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll a, b, dp[19][2][10][10][2], lo, hi;
deque<int> num;

ll solve(int i, bool l, int x, int y, bool z) {
    if(i == num.size())
        return 1;
    if(dp[i][l][x][y][z] != -1)
        return dp[i][l][x][y][z];
    
    ll ans = 0;

    int lim = (l ? 9 : num[i]);

    for(int d = 0; d <= lim; d++) {
        
        bool allowed = (d != x && d != y);
        bool excpt = (z && d==0);
        
        if(allowed || excpt)
            ans += solve(i+1, (d<lim || l), y, d, y==0 && z);
    }
    return dp[i][l][x][y][z] = ans;
}

void init(ll n) {
    memset(dp, -1, sizeof dp);
    num.clear();
    while(n) {
        num.push_front(n%10);
        n /= 10;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> a >> b;

    if(a == 0) {
        lo = 0;
    }else {
        init(a-1);
        lo = solve(0, 0, 0, 0, 1);
    }

    init(b);
    hi = solve(0, 0, 0, 0, 1);

    cout << (hi - lo) << '\n';
}