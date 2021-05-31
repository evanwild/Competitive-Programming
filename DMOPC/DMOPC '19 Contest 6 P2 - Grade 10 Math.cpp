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

int a, b, ans = INT_MAX;

map<int, int> factors(int n) {
    map<int, int> ans;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ans[i]++;
            n /= i;
        }
    }
    if (n > 1)
        ans[n]++;
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> a >> b;

    map<int, int> a_factors = factors(a);
    map<int, int> b_factors;

    for (int i = 1; i <= b; i++) {
        map<int, int> temp = factors(i);
        for (auto x : temp)
            b_factors[x.f] += x.s;
    }

    for (auto x : a_factors)
        ans = min(ans, b_factors[x.f] / x.s);

    cout << ans << '\n';
}