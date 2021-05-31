#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

    vector<pair<int, int>> ans;

    for (int c = 1; c <= m; c++) {
        
        int lo = (n * (c - 1)) / m + 1;
        int hi = (n * c) / m + 1;

        if ((n * c) % m == 0) {
            // if it only touches corner
            hi--;
        }

        for (int r = lo; r <= hi; r++) {
            ans.push_back({r, c});
        }
    }

    cout << ans.size() << '\n';
    for (auto a : ans) {
        cout << a.first << ' ' << a.second << '\n';
    }
}