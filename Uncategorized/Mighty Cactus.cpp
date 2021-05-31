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

int M, K, s, l;
double N, t[5], a[5], x, dmg[200005] = {0};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M >> K;
    for (int i = 0; i < K; i++) cin >> t[i] >> a[i];
    for (int i = 0; i < M; i++) {
        cin >> s >> l >> x;
        dmg[s] += x;
        dmg[s + l] -= x;
    }

    for (int i = 0; i <= 200000; i++) {
        dmg[i] += dmg[i - 1];
        double lo = 1e8;
        for (int j = 0; j < K; j++)
            lo = min(lo, max(0.0, (dmg[i] - t[j]) * (1 - a[j] * 0.01)));
        N -= lo;
    }

    if (N <= 0)
        cout << "Act Like A Cactus.\n";
    else
        cout << fixed << setprecision(2) << N << '\n';
}