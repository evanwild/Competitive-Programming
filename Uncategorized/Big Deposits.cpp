#include <bits/stdc++.h>
using namespace std;

using ll = unsigned long long;

using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using pi = pair<int, int>;
#define f first
#define s second
#define mp make_pair

ll P, Y, T;
ll mx = 1e16;

ll calc(ll n) {
    ll ans = 0;
    for (ll i = 1; i <= Y; i++) {
        ans += n;
        ans += (ans * P) / 100;
    }
    return ans;
}

ll solve(ll l, ll r) {
    if (l == r) return l;
    ll m = (l + r) / 2;
    ll ans = calc(m);
    if (ans < T) return solve(m + 1, r);
    return solve(l, m);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> P >> Y >> T;
    cout << solve(1, mx) << '\n';
}