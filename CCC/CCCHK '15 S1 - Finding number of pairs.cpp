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

int N, M, ans = 0;
vi A;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;
    A.rsz(N);

    for (int i = 0; i < N; i++)
        cin >> A[i];

    sort(all(A));

    int hi = N - 1;

    for (int i = 0; i < N - 1; i++) {
        if (A[i] + A[i + 1] > M)
            break;

        while (A[i] + A[hi] > M)
            hi--;

        if (hi == i)
            break;

        ans = (ans + hi - i) % 1000000007;
    }

    cout << ans << '\n';
}