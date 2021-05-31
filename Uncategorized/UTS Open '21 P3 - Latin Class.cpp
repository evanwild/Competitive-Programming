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

int N;
ll ans[100005];
ll mx = 0;
ll run = 1;
ll mod = 1e9 + 7;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        ll h;
        cin >> h;
        mx = max(mx, h);

        if (h < mx) {
            ans[i] = ans[i - 1];
            run = (run + ans[i]) % mod;
            continue;
        }

        ans[i] = run;
        run = (run + ans[i]) % mod;
    }

    cout << ans[N] << '\n';
}