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

int X, Y, N, M, C, V, H;

int u = 1e6, d = 0, r = 1e6, l = 0;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> X >> Y >> N >> M >> C;
    while (N--) {
        cin >> V;
        l = (V < X ? max(V, l) : l);
        r = (V > X ? min(V, r) : r);
    }
    while (M--) {
        cin >> H;
        d = (H < Y ? max(H, d) : d);
        u = (H > Y ? min(H, u) : u);
    }
    while (C--) {
        cin >> X >> Y;
        cout << (X > l && X < r && Y > d && Y < u ? "Y\n" : "N\n");
    }
}