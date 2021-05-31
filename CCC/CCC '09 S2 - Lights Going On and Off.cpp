#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using pi = pair<int, int>;
#define f first
#define s second
#define mp make_pair

int R, C;
vector<vi> grid, grid_2;
set<int> ans;

void press_buttons(int start) {
    for (int i = start; i >= 1; i--)
        for (int j = 1; j <= C; j++)
            grid_2[i][j] = (grid_2[i][j] != grid_2[i + 1][j]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C;
    grid.rsz(R + 1, vi(C + 1));

    for (int i = R; i >= 1; i--)
        for (int j = 1; j <= C; j++)
            cin >> grid[i][j];

    int hsh = 0;
    for (int i = 1; i <= C; i++)
        hsh = 131 * hsh + grid[1][i];
    ans.insert(hsh);

    for (int i = R - 1; i >= 1; i--) {
        grid_2 = grid;
        press_buttons(i);

        int hsh = 0;
        for (int i = 1; i <= C; i++)
            hsh = 131 * hsh + grid_2[1][i];
        ans.insert(hsh);
    }

    cout << sz(ans) << '\n';
}