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

int H, V, ans = 0;
vi y, x;
unordered_map<int, int> y_diff, x_diff;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> H >> V;
    y.rsz(H);
    x.rsz(V);

    for (int i = 0; i < H; i++) cin >> y[i];
    for (int i = 0; i < V; i++) cin >> x[i];

    for (int i = 0; i < H; i++)
        for (int j = i + 1; j < H; j++) y_diff[y[j] - y[i]]++;

    for (int i = 0; i < V; i++)
        for (int j = i + 1; j < V; j++) x_diff[x[j] - x[i]]++;

    for (auto l : y_diff)
        if (x_diff.count(l.f)) ans += l.s * x_diff[l.f];

    cout << ans << '\n';
}