#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    int f[n];
    for (int i = 0; i < n; i++) {
        cin >> f[i];
    }
    sort(f, f+n);
    reverse(f, f+n);

    int ans = 0;
    for (int i = 0; i < n && i < k; i++) {
        ans += f[i];
    }

    cout << ans << '\n';
}