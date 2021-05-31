#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int on = 0;
    int a[n + 1];

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        on += a[i];  // on stores the number of lights that are on
    }

    if (on == 0) {
        printf("0\n");
        return 0;
    }

    for (int i = 1; i <= m; i++) {
        int b;
        scanf("%d", &b);

        a[b] ^= 1;              // flip the light
        on += (a[b] ? 1 : -1);  // add or subtract whether the light was turned on or off

        if (on <= i) {  // if we are on second i, and there are <= i lights on, it is the answer
            printf("%d\n", i);
            return 0;
        }
    }
    printf("%d\n", on);  // sometimes there will be lights on after all the flips happen
}