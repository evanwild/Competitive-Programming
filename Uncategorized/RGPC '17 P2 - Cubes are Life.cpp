#include <bits/stdc++.h>
using namespace std;
#define LL unsigned long long

LL M, v, psa[100005] = {0};
int N, Q, a, b, idx[1000005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    memset(idx, -1, sizeof idx);

    cin >> N >> M >> Q;

    for(int i = 1; i <= N; i++) {
        cin >> v;
        psa[i] += psa[i-1] + v;
        idx[v] = i;
    }

    while(Q--) {
        cin >> a >> b;

        LL sum = (psa[idx[b]] - psa[idx[a]-1]) / 2;

        if(sum >= M)
            cout << "Enough\n";
        else
            cout << "Not enough\n";
    }
}