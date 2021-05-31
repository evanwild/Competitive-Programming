#include <bits/stdc++.h>

using namespace std;

double N, M, Y;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M >> Y;

    cout << fixed << setprecision(2);

    cout << 0 << ' ' << N << '\n';

    for(int i = 1; i <= Y; i++) {
        N += (N*M)/100.0;
        cout << i << ' ' << N << '\n';
    }
}