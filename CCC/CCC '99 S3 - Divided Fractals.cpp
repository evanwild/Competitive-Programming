#include <bits/stdc++.h>
using namespace std;

int D, N, b, t, l, r, grid[300][300];

void recur(int r, int c, int size) {
    size /= 3;

    for (int i = r + size; i < r + 2 * size; i++)
        for (int j = c + size; j < c + 2 * size; j++) grid[i][j] = 0;

    if (size <= 1) return;

    for (int i = r; i <= r + 2 * size; i += size)
        for (int j = c; j <= c + 2 * size; j += size)
            if (i != r + size || j != c + size) recur(i, j, size);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> D;
    while (D--) {
        cin >> N >> b >> t >> l >> r;
        memset(grid, -1, sizeof grid);
        recur(1, 1, pow(3, N));
        for (int i = t; i >= b; i--) {
            for (int j = l; j <= r; j++) cout << (grid[i][j] ? "* " : "  ");
            cout << '\n';
        }
        cout << '\n';
    }
}