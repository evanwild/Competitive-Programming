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

int N, M, a, b, ans = 0;
int c = 0, h = 0;

map<pi, int> bonds;
char type[1005];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;

    while (M--) {
        cin >> a >> b;
        bonds[mp(a, b)]++;
    }

    for (int i = 1; i <= N; i++) {
        int freq = 0;

        for (auto b : bonds)
            if (b.f.f == i || b.f.s == i)
                freq += b.s;

        if (freq == 1) {
            type[i] = 'H';
            h++;
        } else if (freq == 4) {
            type[i] = 'C';
            c++;
        } else {
            cout << "Impossible\n";
            return 0;
        }
    }

    for (auto b : bonds) {
        char a_type = type[b.f.f];
        char b_type = type[b.f.s];

        if (a_type == 'C' && b_type == 'C') {
            if (b.s == 1)
                ans += 346;
            else
                ans += 615;
        } else if ((a_type == 'C' && b_type == 'H') ||
                   (a_type == 'H' && b_type == 'C')) {
            ans += 413;
        }
    }

    cout << ans << '\n';

    cout << 'C';

    if (c != 1)
        cout << c;
    cout << 'H';
    if (h != 1)
        cout << h;
    cout << '\n';
}