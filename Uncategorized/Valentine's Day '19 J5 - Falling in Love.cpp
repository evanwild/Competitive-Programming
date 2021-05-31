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

ll N, m, b, ans;
unordered_map<ll, ll> slope;
map<pi, ll> same;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    ans = (N * (N - 1)) / 2;

    for (int i = 0; i < N; i++) {
        cin >> m >> b;
        slope[m]++;
        same[mp(m, b)]++;
    }

    for (auto x : slope) {
        ans -= (x.s * (x.s - 1)) / 2;
    }

    for (auto x : same) {
        ans += (x.s * (x.s - 1)) / 2;
    }

    cout << ans << '\n';
}