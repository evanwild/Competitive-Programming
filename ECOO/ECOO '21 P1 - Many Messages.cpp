#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	int min, interval, larry;
	cin >> min >> interval >> larry;

	if (larry > min + 3 * interval) {
		cout << "Who knows...\n";
		return 0;
	}

	min += interval;

	while (true) {
		if (min >= larry) {
			cout << min << '\n';
			break;
		}
		min += interval;
	}

}