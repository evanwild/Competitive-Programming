#include <bits/stdc++.h>
using namespace std;
#define int long long

int vow(char c) {
	if (c == 'A') return 1;
	return 0;
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	string dna;
	cin >> dna;

	string cur = "";
	cur += dna[0];

	for (int i = 1; i < dna.size(); i++) {
		if (vow(cur.back()) != vow(dna[i])) {
			cur += dna[i];
		} else {
			cout << cur << ' ';
			cur = dna[i];
		}
	}

	cout << cur << '\n';

}