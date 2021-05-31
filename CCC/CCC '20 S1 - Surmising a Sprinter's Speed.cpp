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

int N;
pair<double, double> o[100005];
double ans = -1;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> o[i].f >> o[i].s;
    sort(o, o + N);
    for (int i = 0; i < N - 1; i++)
        ans = max(ans, abs(o[i].s - o[i + 1].s) / abs(o[i].f - o[i + 1].f));
    cout << fixed << setprecision(6) << ans << '\n';
}