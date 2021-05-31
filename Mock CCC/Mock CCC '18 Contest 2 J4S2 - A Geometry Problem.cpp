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

vector<pi> side(3);

int main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 0; i < 3; i++) {
        cin >> side[i].f >> side[i].s;
        if (side[i].s > side[i].f)
            swap(side[i].s, side[i].f);
    }

    sort(all(side));

    int l = side[2].f;
    int w = side[2].f - side[2].s;

    // firsts are both w
    if (side[0].f == w && side[1].f == w) {
        if (side[0].s + side[1].s == l) {
            cout << "YES\n";
            return 0;
        }
    }

    // seconds are both w
    if (side[0].s == w && side[1].s == w) {
        if (side[0].f + side[1].f == l) {
            cout << "YES\n";
            return 0;
        }
    }

    // first
    if (side[0].f == w && side[1].s == w) {
        if (side[0].s + side[1].f == l) {
            cout << "YES\n";
            return 0;
        }
    }

    // second
    if (side[0].s == w && side[1].f == w) {
        if (side[0].f + side[1].s == l) {
            cout << "YES\n";
            return 0;
        }
    }
    
    cout << "NO\n";
}