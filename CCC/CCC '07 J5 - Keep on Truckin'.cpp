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

int A, B, N, inp;
vi m = {0,    990,  1010, 1970, 2030, 2940, 3060,
        3930, 4060, 4970, 5030, 5990, 6010, 7000};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> A >> B >> N;
    while (N--) {
        cin >> inp;
        m.pb(inp);
    }
    sort(all(m));

    vector<ll> dp(35);

    dp[0] = 1;

    ll sum = 1;
    int lo = 0;
    int hi = 0;

    for (int i = 1; i < sz(m); i++) {
        while (m[i] - m[lo] > B) {
            sum -= dp[lo];
            lo++;
        }
        while (m[i] - m[hi + 1] >= A) {
            hi++;
            sum += dp[hi];
        }
        dp[i] = sum;
    }

    cout << dp[sz(m) - 1] << '\n';
}