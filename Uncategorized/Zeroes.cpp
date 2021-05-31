#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> d(200, 0);

void mult(int x) {
    vector<int> new_d(200, 0);

    for (int i = 0; i < 200; i++) {
        new_d[i] = d[i] * x;
    }

    for (int i = 0; i < 200; i++) {
            new_d[i + 2] += (new_d[i] / 100);
            new_d[i] -= (new_d[i] / 100) * 100;
            new_d[i + 1] += (new_d[i] / 10);
            new_d[i] -= (new_d[i] / 10) * 10;
    }

    d = new_d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    d[0] = 1;
    for (int i = 2; i <= N; i++) mult(i);

    int last_idx = 199;
    while (d[last_idx] == 0) last_idx--;

    int ans = 0;
    for (int i = 0; i <= last_idx; i++)
        if (d[i] == 0) ans++;
    cout << ans << '\n';
}