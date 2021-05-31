#include <stdio.h>
#define int long long
#define abs(x) (x > 0 ? x : -(x))
#define max(x, y) (x > y ? x : y)

int n, p[200005], w[200005], d[200005];

int val(int c) {
    int ans = 0;
    for (int i = 0; i < n; ++i)
        ans += max((abs(p[i] - c) - d[i]) * w[i], 0);
    return ans;
}

int solve(int l, int r) {
    int m = (l + r) / 2;
    int z[3] = {val(m - 1), val(m), val(m + 1)};
    if (z[1] <= z[0] && z[1] <= z[2])
        return z[1];
    else if (z[1] <= z[0])
        return solve(m + 1, r);
    return solve(l, m - 1);
}

signed main() {
    scanf("%lld", &n);
    for (int i = 0; i < n; ++i)
        scanf("%lld %lld %lld", &p[i], &w[i], &d[i]);
    printf("%lld\n", solve(0, 1e9));
}