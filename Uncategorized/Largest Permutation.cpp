#include <bits/stdc++.h>
using namespace std;

int N, K, a[100005], idx[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        idx[a[i]] = i;
    }

    int lo = 0;
    for (int i = N; i >= 1; i--) {
        if (K == 0) break;
        if (idx[i] == lo) {
            lo++;
            continue;
        }

        int hi = idx[i];
        swap(a[hi], a[lo]);
        swap(idx[a[lo]], idx[a[hi]]);

        lo++;
        K--;
    }

    for (int i = 0; i < N; i++) cout << a[i] << ' ';
    cout << '\n';
}