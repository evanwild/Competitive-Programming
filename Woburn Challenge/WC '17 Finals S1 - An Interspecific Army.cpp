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

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vi c(n), m(n);

    for (auto& x : c)
        cin >> x;

    for (auto& x : m)
        cin >> x;

    sort(all(c));
    sort(all(m));

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, abs(c[i] - m[i]));
    cout << ans << '\n';
}