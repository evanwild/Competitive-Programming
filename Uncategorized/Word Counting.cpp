#include <bits/stdc++.h>
using namespace std;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    int p[n];
    unordered_map<int, int> idx;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        if (!idx.count(p[i])) {
            idx[p[i]] = i + 1;
        }
    }
    sort(p, p+n);

    double w;
    while (q--) {
        cin >> w;
        int ideal = sqrt(w);

        auto hi = upper_bound(p, p+n, ideal);
        auto lo = hi - 1;

        if (hi == p+n) {
            cout << idx[*lo] << ' ';
            continue;
        }
        if (hi == p) {
            cout << idx[*hi] << ' ';
            continue;
        }
        
        if (*lo + w / *lo <= *hi + w / *hi) {
            cout << idx[*lo] << ' ';
        } else {
            cout << idx[*hi] << ' ';
        }
    }
}