#include <bits/stdc++.h>
using namespace std;
#define PI pair<int, int>
#define MP make_pair
#define LL long long
#define F first
#define S second

int n, m;
map<PI, LL> dist;
char grid[1005][1005];
bool visited[1005][1005] = {false};

LL bfs(PI start, PI end) {
    queue<PI> to_visit;

    visited[start.F][start.S] = true;
    to_visit.push(start);
    dist[start] = 0;

    while(!to_visit.empty()) {
        PI current = to_visit.front();
        to_visit.pop();

        for(int i = current.F-1; i <= current.F+1; i++) {
            for(int j = current.S-1; j <= current.S+1; j++) {
                if(abs(i-current.F) == abs(j-current.S)) continue;
                if(i < 0 || i >= n || j < 0 || j >= m) continue;
                if(grid[i][j] == 'X' || visited[i][j]) continue;

                dist[MP(i, j)] = dist[current] + 1;
                visited[i][j] = true;
                to_visit.push(MP(i, j));
            }    
        }
    }

    return dist[end] - 1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    PI start, end;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 's') start = MP(i, j);
            else if(grid[i][j] == 'e') end = MP(i, j);
        }
    }

    cout << bfs(start, end) << endl;

    return 0;
}