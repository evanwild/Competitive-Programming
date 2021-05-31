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

ll N, M, K;
ll a[200005][21];
ll ans = 0;
ll p = 1000000007;

ll get_hsh(int a, int b) {
    return a * p + b;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> M >> N >> K;

    for (int i = 1; i <= M; i++) {
        for (int c = 1; c <= N; c++) {
            cin >> a[i][c];
        }
    }

    for (int c = 2; c <= N; c++) {
        unordered_set<ll> goal;
        for (int i = 1; i <= M; i++) {
            ll cur = a[i][c];
            ll prev = a[i][c - 1];

            goal.insert(get_hsh(cur, prev));

            if (goal.find(get_hsh(cur - K, prev - K)) != goal.end())
                ans++;
            if (goal.find(get_hsh(cur + K, prev + K)) != goal.end())
                ans++;
        }
    }
    cout << ans << '\n';
}