#include <stdio.h>

int c[2000005];

int main() {
    for (int i = 2; i * i <= 2000005; i++)
        if (!c[i])
            for (int j = i * i; j <= 2000005; j += i)
                c[j] = 1;

    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);
        int mx = 2 * n;
        for (int a = n; a >= 2; --a) {
            if (!c[a] && !c[mx - a]) {
                printf("%d %d\n", a, mx - a);
                break;
            }
        }
    }
}