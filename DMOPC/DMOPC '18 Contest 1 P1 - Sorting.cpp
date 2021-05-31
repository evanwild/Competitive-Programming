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

int N, A[200005], last, last_zero, wild, ans = 1;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (A[i] != 0)
            last = i;
        else
            last_zero = i;
    }

    if (A[N - 1] == 0) {
        wild = A[last];
    } else {
        wild = A[last_zero + 1];
    }

    for (int i = N - 1; i >= 0; i--) {
        if (A[i] == 0)
            A[i] = wild;
        if (i != N - 1 && A[i] > A[i + 1])
            ans = 0;
    }

    cout << (ans ? "YES\n" : "NO\n");
}