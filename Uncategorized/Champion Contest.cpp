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

int N, K, a, b;
int v[100005], ans[100005] = {0};
vector<pi> idx;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> v[i];
        idx.pb(mp(v[i], i));
    }
    sort(all(idx));

    for (int i = 1; i < sz(idx); i++) {
        if (idx[i].f == idx[i - 1].f)
            ans[idx[i].s] = ans[idx[i - 1].s];
        else
            ans[idx[i].s] = i;
    }

    for (int i = 0; i < K; i++) {
        cin >> a >> b;
        if (v[a] > v[b])
            ans[a]--;
        else
            ans[b]--;
    }

    for (int i = 1; i <= N; i++) cout << ans[i] << ' ';
    cout << '\n';
}