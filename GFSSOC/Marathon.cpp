#include <bits/stdc++.h>

using namespace std;

int N, Q, a, b, psa[500005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> Q;
    
    for(int i = 1; i <= N; i++) {
        cin >> psa[i];
        psa[i] += psa[i-1];
    }

    while(Q--) {
        cin >> a >> b;
        cout << psa[N] - psa[b] + psa[a-1] << '\n';
    }
}