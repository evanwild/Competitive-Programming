#include <bits/stdc++.h>
using namespace std;
#define int long long

int T;
int l[3];

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> T;
    while (T--) {
        cin >> l[0] >> l[1] >> l[2];
        sort(l, l + 3);
        if (l[0] * l[0] + l[1] * l[1] == l[2] * l[2]) {
            cout << "R\n";
        } else if (l[0] * l[0] + l[1] * l[1] < l[2] * l[2]) {
            cout << "O\n";
        } else {
            cout << "A\n";
        }
    }
}