#include <bits/stdc++.h>

using namespace std;

int N, M, a, b, c;

int lo[1000001], hi[1000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        cin >> c;
        if(!lo[c])
            lo[c] = i;
        hi[c] = i;
    }

    int ans = -1;
    for(int i = 0; i < M; i++) {
        cin >> a >> b;
        if(lo[a] && hi[b])
            ans = max(ans, hi[b]-lo[a]);
    }

    cout << ans+1 << '\n';
}