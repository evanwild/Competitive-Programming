#include <bits/stdc++.h>

using namespace std;

int N;
char p[1005];
char grid[2010][1005];
bool op[2010] = {false};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    memset(grid, '.', sizeof grid);

    cin >> N;

    for(int i = 0; i < N; i++)
        cin >> p[i];

    int row = 1005, col = 0;

    for(int i = 0; i < N; i++) {
        if(p[i] == '^') {
            grid[row][col] = '/';
            col++;
            row--;
        }else if(p[i] == 'v') {
            row++;
            grid[row][col] = '\\';
            col++;
        }else {
            grid[row][col] = '_';
            col++;
        }
    }

    for(int i = 0; i < 2010; i++) {
        for(int j = 0; j < N; j++) {
            if(grid[i][j] != '.') {
                op[i] = true;
                break;
            }
        }
    }

    for(int i = 0; i < 2010; i++) {
        if(op[i]) {
            for(int j = 0; j < N; j++) {
                cout << grid[i][j];
            }
            cout << endl;
        }
    }
}