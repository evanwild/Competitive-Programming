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

int N, Q, l, r;
ll ans = 0;
ll a[100005], freq[100005];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> Q;

    for (int i = 1; i <= N; i++) cin >> a[i];
    sort(a + 1, a + N + 1);

    while (Q--) {
        cin >> l >> r;
        freq[l]++;
        freq[r + 1]--;
    }

    for (int i = 1; i <= N; i++) freq[i] += freq[i - 1];
    sort(freq + 1, freq + N + 1);

    int ptr = 1;
    for (int i = N; i >= 1; i--) {
        ans += freq[ptr] * a[i];
        ptr++;
    }

    cout << ans << '\n';
}