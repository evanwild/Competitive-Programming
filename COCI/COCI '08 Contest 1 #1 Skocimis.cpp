#include <bits/stdc++.h>

using namespace std;

int A, B, C;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> A >> B >> C;

    cout << max(
        C - B - 1,
        B - A - 1
    ) << '\n';
}