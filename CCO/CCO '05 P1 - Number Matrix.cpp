#include <iostream>
#include <iomanip>
#include <map>
#include <vector>

using namespace std;

int n, m;
int matrix[105][105];
int best_a = 100, best_b = 100, best_c = 100;
bool visited[105][105][11][11][11] = {false};

void solve(int row, int col, int a, int b, int c) {

    // cout << "CALLED WITH " << row << " " << col << " " << a << " " << b << " " << c << endl;

    if(visited[row][col][a+1][b+1][c+1]) {
        return;
    }

    visited[row][col][a+1][b+1][c+1] = true;

    if(row == m-1) {
        if(a < best_a) {
            best_a = a;
            best_b = b;
            best_c = c;
        }else if(a == best_a) {
            if(b < best_b) {
                best_a = a;
                best_b = b;
                best_c = c;
            }else if(b == best_b) {
                if(c < best_c) {
                    best_a = a;
                    best_b = b;
                    best_c = c;
                }
            }
        }
    }else {

        // DOWN
        int move = matrix[row+1][col];
        if(move == a || move == b || move == c) {
            solve(row+1, col, a, b, c);
        }else {
            if(b == -1) {
                solve(row+1, col, a, move, c);
            }else if(c == -1) {
                solve(row+1, col, a, b, move);
            }
        }
        // UP
        if(row != 0) {
            int move = matrix[row-1][col];
            if(move == a || move == b || move == c) {
                solve(row-1, col, a, b, c);
            }else {
                if(b == -1) {
                    solve(row-1, col, a, move, c);
                }else if(c == -1) {
                    solve(row-1, col, a, b, move);
                }
            }
        }

        // LEFT
        if(col != 0) {
            int move = matrix[row][col-1];
            if(move == a || move == b || move == c) {
                solve(row, col-1, a, b, c);
            }else {
                if(b == -1) {
                    solve(row, col-1, a, move, c);
                }else if(c == -1) {
                    solve(row, col-1, a, b, move);
                }
            }
        }

        // RIGHT
        if(col != n-1) {
            int move = matrix[row][col+1];
            if(move == a || move == b || move == c) {
                solve(row, col+1, a, b, c);
            }else {
                if(b == -1) {
                    solve(row, col+1, a, move, c);
                }else if(c == -1) {
                    solve(row, col+1, a, b, move);
                }
            }
        }
    }
}

int main() {

    cin >> n >> m;

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> matrix[i][j];

    for(int i = 0; i < n; i++) {
        solve(0, i, matrix[0][i], -1, -1);
    }

    if(best_c == 100) {
        cout << "-1 -1 -1" << endl;
    }else {
        if(best_a == -1) {
            best_a = 0;
        }
        if(best_b == -1) {
            best_b = 0;
        }
        if(best_c == -1) {
            best_c = 0;
        }
        if(best_a <= best_b && best_b <= best_c) {
            cout << best_a << " " << best_b << " " << best_c << endl;
        }else if(best_a <= best_b && best_c <= best_b) {
            cout << best_a << " " << best_c << " " << best_b << endl;
        }else if(best_b <= best_a && best_a <= best_c) {
            cout << best_b << " " << best_a << " " << best_c << endl;
        }else if(best_b <= best_a && best_c <= best_a) {
            cout << best_b << " " << best_c << " " << best_a << endl;
        }else if(best_c <= best_a && best_a <= best_b) {
            cout << best_c << " " << best_a << " " << best_b << endl;
        }else if(best_c <= best_a && best_b <= best_a) {
            cout << best_c << " " << best_b << " " << best_a << endl;
        }
    }
    return 0;
}