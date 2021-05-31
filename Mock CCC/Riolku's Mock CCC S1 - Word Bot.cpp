#include <bits/stdc++.h>
using namespace std;

#define int long long

int N, C, V;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >> C >> V;

    int c = 0, v = 0;

    while (N--) {
        char x;
        cin >> x;

        if (x == 'y') {
            ++c;
            ++v;
        } else if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
            ++v;
            c = 0;
        } else {
            ++c;
            v = 0;
        }

        if (c > C || v > V) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
}