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

struct node {
    int lo, gcd, freq;
};

int N, M, x, v, l, r;
char op;
int arr[100005];
node tree[262144];

void build(int l, int r, int p) {
    if (l == r) {
        tree[p] = node{arr[l], arr[l], 1};
        return;
    }
    int m = (l + r) / 2;
    build(l, m, 2 * p + 1);
    build(m + 1, r, 2 * p + 2);

    tree[p] = node{min(tree[2 * p + 1].lo, tree[2 * p + 2].lo),
                   __gcd(tree[2 * p + 1].gcd, tree[2 * p + 2].gcd), 0};

    if (tree[p].gcd == tree[2 * p + 1].gcd)
        tree[p].freq += tree[2 * p + 1].freq;
    if (tree[p].gcd == tree[2 * p + 2].gcd)
        tree[p].freq += tree[2 * p + 2].freq;
}

node query(int ql, int qr, int l, int r, int p) {
    if (ql <= l && qr >= r)
        return tree[p];
    if (ql > r || qr < l) {
        return node{INT_MAX, 0, 0};
    }
    int m = (l + r) / 2;

    node left = query(ql, qr, l, m, 2 * p + 1);
    node right = query(ql, qr, m + 1, r, 2 * p + 2);

    node ans{min(left.lo, right.lo), __gcd(left.gcd, right.gcd), 0};
    if (ans.gcd == left.gcd)
        ans.freq += left.freq;
    if (ans.gcd == right.gcd)
        ans.freq += right.freq;

    return ans;
}

void update(int x, int v, int l, int r, int p) {
    if (l == r) {
        tree[p] = node{v, v, 1};
        return;
    }
    int m = (l + r) / 2;
    if (x <= m) {
        update(x, v, l, m, 2 * p + 1);
    } else {
        update(x, v, m + 1, r, 2 * p + 2);
    }

    tree[p] = node{min(tree[2 * p + 1].lo, tree[2 * p + 2].lo),
                   __gcd(tree[2 * p + 1].gcd, tree[2 * p + 2].gcd), 0};

    if (tree[p].gcd == tree[2 * p + 1].gcd)
        tree[p].freq += tree[2 * p + 1].freq;
    if (tree[p].gcd == tree[2 * p + 2].gcd)
        tree[p].freq += tree[2 * p + 2].freq;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> arr[i];
    build(0, N - 1, 0);

    while (M--) {
        cin >> op;
        if (op == 'M') {
            cin >> l >> r;
            cout << query(l - 1, r - 1, 0, N - 1, 0).lo << '\n';
        } else if (op == 'G') {
            cin >> l >> r;
            cout << query(l - 1, r - 1, 0, N - 1, 0).gcd << '\n';
        } else if (op == 'C') {
            cin >> x >> v;
            update(x - 1, v, 0, N - 1, 0);
        } else if (op == 'Q') {
            cin >> l >> r;
            cout << query(l - 1, r - 1, 0, N - 1, 0).freq << '\n';
        }
    }
}