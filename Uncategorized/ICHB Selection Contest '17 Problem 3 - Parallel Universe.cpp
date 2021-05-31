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

ll N, Q, x, y, val;
ll arr[100005];
ll tree[262144];

void build(int l, int r, int pos) {
    if (l == r) {
        tree[pos] = arr[l];
    } else {
        int m = (l + r) / 2;
        build(l, m, 2 * pos + 1);
        build(m + 1, r, 2 * pos + 2);
        tree[pos] = tree[2 * pos + 1] & tree[2 * pos + 2];
    }
}

int query(int ql, int qr, int l, int r, int pos) {
    if (ql <= l && qr >= r)
        return tree[pos];
    if (ql > r || qr < l)
        return -1;
    int m = (l + r) / 2;
    ll q1 = query(ql, qr, l, m, 2 * pos + 1);
    ll q2 = query(ql, qr, m + 1, r, 2 * pos + 2);

    if (q1 == -1)
        return q2;
    if (q2 == -1)
        return q1;

    return q1 & q2;
}

void update(int idx, ll val, int l, int r, int pos) {
    if (l == r) {
        tree[pos] = val;
        return;
    }

    int m = (l + r) / 2;
    if (idx <= m)
        update(idx, val, l, m, 2 * pos + 1);
    else
        update(idx, val, m + 1, r, 2 * pos + 2);

    if (tree[2 * pos + 1] == -1)
        tree[pos] = tree[2 * pos + 2];
    else if (tree[2 * pos + 2] == -1)
        tree[pos] = tree[2 * pos + 1];
    else
        tree[pos] = tree[2 * pos + 1] & tree[2 * pos + 2];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> Q;

    for (int i = 0; i < N; i++)
        cin >> arr[i];
    build(0, N - 1, 0);

    char op;
    while (Q--) {
        cin >> op;
        if (op == 'U') {
            cin >> x >> val;
            update(x - 1, val, 0, N - 1, 0);
        } else {
            cin >> x >> y >> val;
            cout << (val & query(x - 1, y - 1, 0, N - 1, 0)) << '\n';
        }
    }
}