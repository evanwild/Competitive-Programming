#include <bits/stdc++.h>

using namespace std;

int T, M, R, C;

int grid[5][5] = {
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,2,0,0},
    {0,2,1,2,0},
    {0,1,1,1,0}
};

bool solve(int m) {
    int r = R / pow(5, m-1);
    int c = C / pow(5, m-1);

    if(grid[r][c] != 2)
        return grid[r][c];

    if(m == 1 && grid[r][c] == 2)
        return 0;

    R -= r * pow(5, m-1);
    C -= c * pow(5, m-1);

    return solve(m-1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> T;
    while(T--) {
        cin >> M >> C >> R;

        R = pow(5, M) - 1 - R;

        if(solve(M))
            cout << "crystal\n";
        else
            cout << "empty\n";
    }
}