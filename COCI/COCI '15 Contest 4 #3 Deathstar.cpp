#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            int m;
            scanf("%d", &m);
            ans |= m;
        }
        printf("%d ", ans);
    }
    printf("\n");
}