#include <bits/stdc++.h>
using namespace std;

int P, R, N;
int ans = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> P >> N >> R;
    P -= N;

    while(P >= 0) {
        N *= R;
        P -= N;
        ans++;
    }

    cout << ans << '\n';
}