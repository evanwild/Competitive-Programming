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

int N, M;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    while (N--) {
        cin >> M;
        for (int i = 2; i * i <= M; i++) {
            while (M % i == 0) {
                cout << i << ' ';
                M /= i;
            }
        }
        if (M != 1)
            cout << M;
        cout << '\n';
    }
}