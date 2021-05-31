#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;

void solve(int i) {
	if(i != 1)
		solve(i - 1);
	printf("%d X %d = %d\n", N, i, N*i);
}

int main() {
	cin >> N;
	solve(N);
}