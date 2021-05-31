#include <stdio.h>
#include <string.h>
int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    unsigned long long f[100005];
    memset(f, 0, sizeof f);
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        ++f[a];
    }
    for (int i = 0; i < q; ++i) {
        int o, v;
        scanf("%d %d", &o, &v);
        if (o == 1) {
            f[v >> 1] += f[v];
            f[(v >> 1) + (v & 1)] += f[v];
            f[v] = 0;
        } else {
            printf("%llu\n", f[v]);
        }
    }
}