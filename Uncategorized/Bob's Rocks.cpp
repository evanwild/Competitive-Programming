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

int n, a, freq[51], ans = 0;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    while (n--) {
        cin >> a;
        freq[a]++;
    }

    for (int i = 0; i <= 50; i++)
        if (freq[i] * i > freq[ans] * ans)
            ans = i;

    cout << ans << '\n';
}