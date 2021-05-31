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

ll N;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    for (ll S = 1; S <= 1000000; S++) {
        ll fit;
        if (S % 2 == 0)
            fit = (S / 2) * (S / 2) + (S / 2 + 1) * (S / 2 + 1);
        else
            fit = ((S + 1) / 2) * (S + 1);

        if (fit >= N) {
            cout << S << '\n';
            return 0;
        }
    }
}