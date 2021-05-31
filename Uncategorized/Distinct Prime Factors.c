#include <stdio.h>
#include <string.h>

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    int ans[b + 1];
    memset(ans, 0, sizeof ans);
    for (int i = 2; i <= b; i++)
        if (ans[i] == 0)
            for (int j = i; j <= b; j += i) ans[j]++;

    for (int i = a; i <= b; i++) {
        printf("%d\n", ans[i]);
    }
}