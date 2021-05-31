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

int R, C, ans = 0;
char grid[35][50];
bool vis[35][50] = {0};
pi d[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool valid(int i, int j) {
    if (i < 0 || j < 0 || i >= R || j >= C) return 0;
    if (vis[i][j]) return 0;
    if (grid[i][j] == '#') return 0;
    return 1;
}

bool flood(int i, int j) {
    if (!valid(i, j)) return 0;
    vis[i][j] = 1;
    bool ans = (grid[i][j] == 'M');
    for (int k = 0; k < 4; k++)
        if (flood(i + d[k].f, j + d[k].s)) ans = 1;
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++) cin >> grid[i][j];

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (flood(i, j)) ans++;

    cout << ans << '\n';
}