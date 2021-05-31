#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    int a[n+1], psa[n+1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        psa[i] = psa[i-1] + a[i];
    }

    int l, r;
    while (q--) {
        cin >> l >> r;
        int count = r - l + 1;
        int sum = psa[r] - psa[l-1];
        cout << (sum / count) << '\n';
    }
}