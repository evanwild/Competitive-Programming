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

int N, Q, a, b;
int arr[50005];
pi tree[131072];

void build(int l, int r, int pos) {
    if (l == r) {
        tree[pos] = mp(arr[l], arr[l]);
    } else {
        int m = (l + r) / 2;
        build(l, m, 2 * pos + 1);
        build(m + 1, r, 2 * pos + 2);
        tree[pos].f = min(tree[2 * pos + 1].f, tree[2 * pos + 2].f);
        tree[pos].s = max(tree[2 * pos + 1].s, tree[2 * pos + 2].s);
    }
}

pi query(int ql, int qr, int l, int r, int pos) {
    if (ql <= l && qr >= r)
        return tree[pos];
    if (ql > r || qr < l)
        return mp(INT_MAX, INT_MIN);
    int m = (l + r) / 2;
    pi q1 = query(ql, qr, l, m, 2 * pos + 1);
    pi q2 = query(ql, qr, m + 1, r, 2 * pos + 2);
    return mp(min(q1.f, q2.f), max(q1.s, q2.s));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> Q;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    build(0, N - 1, 0);

    while (Q--) {
        cin >> a >> b;
        pi q = query(a - 1, b - 1, 0, N - 1, 0);
        cout << q.s - q.f << '\n';
    }
}