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

int T, N, grid[25][25], dist[25][25];

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

bool valid(pi x) {
    return (x.f >= 0 && x.s >= 0 && x.f < N && x.s < N && dist[x.f][x.s] == -1);
}

void solve() {
    memset(dist, -1, sizeof dist);
    queue<pi> q;

    dist[0][0] = 0;
    q.push(mp(0, 0));

    while (!q.empty()) {
        pi u = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            pi v = mp(u.f + dr[i], u.s + dc[i]);
            if (!valid(v)) continue;
            if (abs(grid[u.f][u.s] - grid[v.f][v.s]) <= 2) {
                q.push(v);
                bool add = (grid[u.f][u.s] > grid[0][0] ||
                            grid[v.f][v.s] > grid[0][0]);
                dist[v.f][v.s] = dist[u.f][u.s] + add;
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) cin >> grid[i][j];

        solve();

        if (dist[N - 1][N - 1] == -1)
            cout << "CANNOT MAKE THE TRIP\n";
        else
            cout << dist[N - 1][N - 1] << '\n';

        if (T != 0) cout << '\n';
    }
}