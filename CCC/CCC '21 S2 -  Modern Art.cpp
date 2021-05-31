#include <bits/stdc++.h>
using namespace std;

// single quote test
int row[5'000'005];
int col[5'000'005];

int main() {
	int m, n, k;
	cin >> m >> n >> k;

	while (k--) {
		char op;
		int val;
		cin >> op >> val;

		if (op == 'R') {
			row[val] ^= 1;
		} else {
			col[val] ^= 1;
		}
	}

	int ans = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			ans += (row[i] + col[j]) & 1;
		}
	}

	cout << ans << '\n';
}