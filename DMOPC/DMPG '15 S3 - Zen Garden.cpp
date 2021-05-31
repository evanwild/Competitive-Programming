#include <bits/stdc++.h>

using namespace std;

int N, M, f[100005];
int a, d, ans = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> N;

    for(int i = 1; i <= N; i++) {
        cin >> f[i];
        ans += f[i];
    }

    cin >> M;

    while(M--) {
        cin >> a >> d;
        if(d > f[a] || d > f[a+1]) {
            ans -= min(f[a], f[a+1]);
        }else {
            ans -= d;
        }
    }

    cout << ans << '\n';
}