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
double P, C;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    while (N--) {
        cin >> P >> C;
        double O = P / (C / 100 + 1);
        cout << fixed << setprecision(7) << O << '\n';
    }
}