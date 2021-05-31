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

int N, M, a[100005], tree[262144];

void make(int l, int r, int i) {
    if (l == r) {
        tree[i] = a[l];
        return;
    }
    int m = (l + r) / 2;
    make(l, m, 2 * i + 1);
    make(m + 1, r, 2 * i + 2);
    tree[i] = min(tree[2 * i + 1], tree[2 * i + 2]);
}

int query(int ql, int qr, int l, int r, int i) {
    if (ql <= l && qr >= r)
        return tree[i];
    if (ql > r || qr < l)
        return INT_MAX;
    int m = (l + r) / 2;
    return min(query(ql, qr, l, m, 2 * i + 1),
               query(ql, qr, m + 1, r, 2 * i + 2));
}

void update(int qv, int qi, int l, int r, int i) {
    if (l == r) {
        tree[i] = qv;
        return;
    }
    int m = (l + r) / 2;
    if (qi <= m)
        update(qv, qi, l, m, 2 * i + 1);
    else
        update(qv, qi, m + 1, r, 2 * i + 2);

    tree[i] = min(tree[2 * i + 1], tree[2 * i + 2]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> a[i];

    make(0, N - 1, 0);

    char op;
    int i, j;

    while (M--) {
        cin >> op >> i >> j;
        if (op == 'Q')
            cout << query(i, j, 0, N - 1, 0) << '\n';
        else
            update(j, i, 0, N - 1, 0);
    }
}