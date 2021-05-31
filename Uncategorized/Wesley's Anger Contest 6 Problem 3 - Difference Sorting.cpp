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

ll N, a[200005], b[200005], diff[200005], tree[524288];

void construct_tree(int lo, int hi, int pos) {
    if (lo == hi) {
        tree[pos] = diff[lo];
        return;
    }
    int mid = (lo + hi) / 2;
    construct_tree(lo, mid, 2 * pos + 1);
    construct_tree(mid + 1, hi, 2 * pos + 2);
    tree[pos] = max(tree[2 * pos + 1], tree[2 * pos + 2]);
}

ll max_query(int qlo, int qhi, int lo, int hi, int pos) {
    if (qlo <= lo && qhi >= hi)
        return tree[pos];
    if (qlo > hi || qhi < lo)
        return 0;
    int mid = (lo + hi) / 2;
    return max(max_query(qlo, qhi, lo, mid, 2 * pos + 1),
               max_query(qlo, qhi, mid + 1, hi, 2 * pos + 2));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(b, b + N);

    for (int i = 0; i < N - 1; i++)
        diff[i] = b[i + 1] - b[i];

    construct_tree(0, N - 2, 0);

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        if (b[i] < a[i]) {
            int lo = int(lower_bound(b, b + N, b[i]) - b);
            int hi = int(lower_bound(b, b + N, a[i]) - b);
            ans = max(ans, max_query(lo, hi - 1, 0, N - 2, 0));
        }
    }

    cout << ans << '\n';
}