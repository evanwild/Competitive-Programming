#include <bits/stdc++.h>

using namespace std;

int T, L, N, M;
int C, R, D, H;
int diff[1005], dmg[1005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> T;
    while(T--) {

        cin >> L >> N;

        memset(diff, 0, sizeof diff);
        for(int i = 1; i <= N; i++) {
            cin >> C >> R >> D;

            if(C - R < 1)
                diff[1] += D;
            else
                diff[C-R] += D;

            if(C + R > L)
                diff[L+1] -= D;
            else
                diff[C+R+1] -= D;
        }

        dmg[1] = diff[1];
        for(int i = 2; i <= L; i++)
            dmg[i] = dmg[i-1] + diff[i];

        cin >> M;
        while(M--) {
            cin >> H;
            int ans = 0;

            for(; ans <= L; ans++) {
                H -= dmg[ans];
                if(H <= 0)
                    break;
            }

            if(H <= 0)
                cout << ans << '\n';
            else
                cout << "Bloon leakage\n"; 
        }
    }
}