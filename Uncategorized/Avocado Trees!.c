#include <stdio.h>

int main() {
    int n, q, h;
    scanf("%d %d %d", &n, &q, &h);
    int psa[n + 1];
    for (int i = 1; i <= n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        psa[i] = psa[i - 1];
        psa[i] += (a <= h ? b : 0);
    }
    int ans = -1;
    while (q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        int tmp = psa[r] - psa[l-1];
        ans = (tmp > ans ? tmp : ans);
    }
    printf("%d\n", ans);
}