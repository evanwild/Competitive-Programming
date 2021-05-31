#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	int k;
	cin >> k;

	k++;

	vector<int> facts;

	for (int i = 2; i*i <= k; i++) {
		while(k % i == 0) {
			facts.push_back(i);
			k /= i;
		}
	}

	if(k != 1) {
		facts.push_back(k);
	}

	int fact_sum = 0;
	for (auto f : facts) {
		fact_sum += f - 1;
	}

	if (fact_sum > 100000) {
		cout << "Sad Chris\n";
		return 0;
	}

	cout << fact_sum << '\n';

	int n = 1;
	for (auto f : facts) {
		for (int i = 0; i < f - 1; i++) {
			cout << n << ' ';
		}
		n++;
	}
}