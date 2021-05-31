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

int N, T, ans = INT_MAX;
vi pump;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> T;
    pump.rsz(N);

    for (int i = 0; i < N; i++) cin >> pump[i];
    pump.pb(0);
    sort(all(pump));

    int start = -1;
    for (int i = 0; i <= N; i++)
        if (pump[i] == 0) start = i;

    for (int l = 0; l <= start; l++)
        for (int r = start; r <= N; r++)
            if (r - l == T)
                ans = min({ans, 2 * pump[r] + abs(pump[l]),
                           abs(pump[l]) * 2 + pump[r]});
    cout << ans << '\n';
}