#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    int i;
    while (n--) {
        cin >> i;

        while (i % 2 == 0) {
            i /= 2;
        }

        cout << (i == 1 ? "T\n" : "F\n");
    }

}