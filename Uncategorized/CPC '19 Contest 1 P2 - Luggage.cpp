#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using pi = pair<int, int>;
#define f first
#define s second
#define mp make_pair

int N, K, ans = -1;
vi h;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> K;
    h.rsz(N);

    for (int i = 0; i < N; i++) cin >> h[i], h[i] *= -1;
    sort(all(h));

    for (int i = 0; i < N; i++) {
        auto hi = lower_bound(all(h), h[i] - K);
        if (hi != h.end()) ans = max(ans, i - int(hi - h.begin()));
    }
    cout << ans + 1 << '\n';
}