#include <bits/stdc++.h>

using namespace std;

int n[3];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n[0] >> n[1] >> n[2];
    sort(n, n+3);

    int d = min(
        n[1]-n[0],
        n[2]-n[1]
    );

    if(n[2]-n[1] > d)
        cout << n[1] + d << '\n';
    else if(n[1]-n[0] > d)
        cout << n[0] + d << '\n';
    else
        cout << n[2] + d << '\n';
}