#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    int p;
    int ans = 0;
    while (n--) {
        cin >> p;

        int exp = p % 10;
        p /= 10;

        int add = 1;
        while(exp--) {
            add *= p;
        }

        ans += add;
    }

    cout << ans << '\n';
}