#include <bits/stdc++.h>

using namespace std;

string G;
int Q, i, j, psa[100005]={0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> G >> Q;

    for(int i = 0; i < G.size(); i++)
        psa[i] += psa[i-1] + (G[i] == 'G');

    while(Q--) {
        cin >> i >> j;
        cout << psa[j] - psa[i-1] << '\n';
    }
}