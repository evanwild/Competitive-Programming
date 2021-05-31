#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int N, P, Q, a[10000005], psa[10000005] = {0};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> P >> Q;

    for (int i = 0; i < N; i++) cin >> a[i];

    for (int i = 0; i < N; i++) {
        a[i] = (a[i] + psa[i]) % 1000000007;
        cout << a[i] << ' ';
        int first_add = N - ((N - i) * P) / Q;
        if (first_add < N) psa[first_add] = (2 * a[i]) % 1000000007;
    }
    cout << endl;
}