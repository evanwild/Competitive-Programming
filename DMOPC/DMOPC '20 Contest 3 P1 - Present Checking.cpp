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
bool freq[1000005];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    int x;
    for (int i = 0; i < N; i++) {
        cin >> x;
        if (freq[x]) {
            cout << "NO\n";
            return 0;
        }
        freq[x] = 1;
    }

    for (int i = 1; i <= N; i++) {
        if (!freq[i]) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
}