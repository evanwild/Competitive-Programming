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

int N, M, Q, ans;
vi v, gaps;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M >> Q;
    v.rsz(Q);

    for (int i = 0; i < Q; i++) cin >> v[i];
    sort(all(v));

    for (int i = 0; i < Q - 1; i++)
        if (v[i] + 1 != v[i + 1]) gaps.pb(v[i + 1] - v[i] - 1);

    sort(all(gaps));

    int ans = v[sz(v) - 1] - v[0] + 1;

    for (int i = sz(gaps) - 1; i >= 0; i--) {
        M--;
        if (M == 0) break;
        ans -= gaps[i];
    }

    cout << ans << '\n';
}