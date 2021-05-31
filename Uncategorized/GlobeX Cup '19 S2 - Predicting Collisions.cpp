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

double N, M, a, b;
double N_co[6], M_co[6];
double prec = 1e-8;

double f(double x) {
    double ans = 0;
    for (int i = N; i >= 0; i--) ans += N_co[i] * pow(x, i);
    return ans;
}

double g(double x) {
    double ans = 0;
    for (int i = M; i >= 0; i--) ans += M_co[i] * pow(x, i);
    return ans;
}

double solve(double l, double r) {
    double m = (l + r) / 2.0;
    if (r - l <= prec) return m;

    double curr = f(m) - g(m);
    double up = f(r) - g(r);
    double down = f(l) - g(l);

    if (abs(up) <= prec) return r;
    if (abs(down) <= prec) return l;

    if ((up < 0) == (curr < 0)) return solve(l, m);
    return solve(m, r);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    for (int i = N; i >= 0; i--) cin >> N_co[i];
    cin >> M;
    for (int i = M; i >= 0; i--) cin >> M_co[i];
    cin >> a >> b;

    cout << fixed << setprecision(8) << solve(a, b) << '\n';
}