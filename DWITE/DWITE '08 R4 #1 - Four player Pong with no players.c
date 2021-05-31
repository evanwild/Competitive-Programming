#include <stdio.h>
#include <stdlib.h>

void solve() {
    int h, v;
    scanf("%d%d", &h, &v);

    float time_h = (h ? abs(50 * (1.0 / h)) : 9999);
    float time_v = (v ? abs(25 * (1.0 / v)) : 9999);

    if (time_h < time_v) {
        printf("%d,%d\n", 50 + (int)time_h * h, 25 + (int)time_h * v);
    } else {
        printf("%d,%d\n", 50 + (int)time_v * h, 25 + (int)time_v * v);
    }
}

int main() {
    for (int i = 0; i < 5; i++) {
        solve();
    }
}