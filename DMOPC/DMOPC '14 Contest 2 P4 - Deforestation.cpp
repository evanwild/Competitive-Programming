#include <bits/stdc++.h>

using namespace std;

int N, Q, a, b, psa[1000005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> psa[i];
        psa[i] += psa[i-1];
    }

    cin >> Q;

    while(Q--) {
        cin >> a >> b;
        cout << psa[b] - psa[a-1] << '\n';
    }
}