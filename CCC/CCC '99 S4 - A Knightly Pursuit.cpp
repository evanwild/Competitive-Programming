#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

int tc, R, C, PR, PC, KR, KC;
bool vis[102][102][102];

pair<int, int> moves[] = {
    {2,1}, {2,-1}, {-2,1}, {-2,-1}, {1,2}, {1,-2}, {-1,2}, {-1,-2}
};

int solve1(int pr, int kr, int kc) {
    if(kc == PC && kr == pr && kr != R)
        return 0;
    if(kc == PC && kr == pr+1)
        return 999999;
    if(pr == R)
        return 999999;

    vis[pr][kr][kc] = 1;
    int ans = 999999;
    for(auto move : moves) {
        int kr2 = kr + move.F;
        int kc2 = kc + move.S;
        if(kr2 <= R && kr2 >= 1 && kc2 <= C && kc2 >= 1)
            if(!vis[pr+1][kr2][kc2])
                ans = min(ans, solve1(pr+1, kr2, kc2)+1);
    }
    return ans;
}

int solve2(int pr, int kr, int kc) {
    if(kc == PC && kr == pr+1)
        return 0;
    if(kc == PC && kr == pr)
        return 999999;
    if(pr == R)
        return 999999;

    vis[pr][kr][kc] = 1;
    int ans = 999999;
    for(auto move : moves) {
        int kr2 = kr + move.F;
        int kc2 = kc + move.S;
        if(kr2 <= R && kr2 >= 1 && kc2 <= C && kc2 >= 1)
            if(!vis[pr+1][kr2][kc2])
                ans = min(ans, solve2(pr+1, kr2, kc2)+1);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> tc;

    while(tc--) {
        cin >> R >> C >> PR >> PC >> KR >> KC;

        memset(vis, 0, sizeof vis);
        int ans1 = solve1(PR, KR, KC);

        memset(vis, 0, sizeof vis);
        int ans2 = solve2(PR, KR, KC);
        
        int ans3 = R - PR - 1;

        if(ans1 != 999999) {
            cout << "Win in " << ans1 << " knight move(s).\n";
        }else if(ans2 != 999999) {
            cout << "Stalemate in " << ans2 << " knight move(s).\n";
        }else {
            cout << "Loss in " << ans3 << " knight move(s).\n";
        }
    }
}