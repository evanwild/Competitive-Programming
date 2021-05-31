#include <cstdio>
#include <algorithm>
#define ll long long
#define s second
#define f first
char _, __;
#define scanu(x) do{while((x=getchar())<'0');for(x-='0';'0'<=(_=getchar());x=x*10+_-'0');}while(0)
ll ans, min, x;
inline ll m(const ll &x){
	return x >= 1000000007 ? x % 1000000007 : x;
}
int main() {
	int n; scanu(n);
	std::pair<ll,ll> c[n];
	for(int i = 0; i < n; ++i) {
		scanu(c[i].f); scanu(c[i].s);
	}
	sort(c, c+n);
	for(int i = 0; i < n; i++) {
		x = m(m(c[i].s*(c[i].s+1))*500000004);
		ans = m(ans+m(m(min*c[i].s)+m(c[i].f*x)));
		min = m(min+m(c[i].f*c[i].s));
	}
	printf("%lld\n", ans);
}