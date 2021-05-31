#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using pi = pair<int, int>;
#define f first
#define s second
#define mp make_pair

#define int long long

int D, N;

bool prime(int n) {
	if(n <= 2) return (n == 2);
	if(n % 2 == 0) return 0;
	for(int i = 3; i*i <= n; i += 2)
		if(n % i == 0)
			return 0;
	return 1;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> D >> N;
    D = max(D, 1LL);
  	N = max(N, ll(powl(10, 2 * D - 1)));
	  
    for(int ans = N; ; ans++) {
    	string str_ans = to_string(ans);
		for(int i = D - 1; str_ans.size() - i - 1 >= D; i++) {
			if(str_ans[i + 1] != '0' && prime(stoi(str_ans.substr(0, i + 1))) && prime(stoi(str_ans.substr(i + 1, str_ans.size() - i - 1)))) {
				cout << ans << '\n';
				return 0;
			}
		}
	}
}