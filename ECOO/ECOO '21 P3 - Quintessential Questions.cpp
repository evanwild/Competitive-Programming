#include <bits/stdc++.h>
using namespace std;
#define int long long

int mx[200005];
int ans[200005];

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	memset(ans, -1, sizeof ans);

	int n, m, k;
	cin >> n >> m >> k;

	int a, b, c;
	for (int i = 0; i < k; i++) {
		cin >> a >> b >> c;

		if (c > mx[b]) {
			mx[b] = c;
			ans[b] = a;
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}