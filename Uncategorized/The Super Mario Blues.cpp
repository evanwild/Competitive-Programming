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

int T, w, l;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> T;
    while (T--) {
        cin >> w >> l;
        l *= -1; // get rid of dash

        int ans = 0;

        while (1) {
            if (w == 9)
                break;
            ans++;
            l++;

            if (w == 1 && l == 3)
                w = 4, l = 1;

            if (w == 4 && l == 3)
                w = 8, l = 1;

            if (l == 5)
                w++, l = 1;
        }

        cout << ans << '\n';
    }
}