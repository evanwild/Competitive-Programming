#include <bits/stdc++.h>

using namespace std;

int T, N, H, W, l, r, u, d;
bool ugly_code = false;
bool c[510][510];
map<string, int> solve= {
    {"1011111", 0},
    {"0000011", 1},
    {"1110110", 2},
    {"1110011", 3},
    {"0101011", 4},
    {"1111001", 5},
    {"1111101", 6},
    {"1000011", 7},
    {"1111111", 8},
    {"1111011", 9}
};

void find_edges() {
    ugly_code = false;
    for(int i = 3; i < H+3; i++) {
        for(int j = 3; j < W+3; j++) {
            if(c[i][j]) {
                l = min(l, j);
                r = max(r, j);
                u = min(u, i);
                d = max(d, i);
            }
        }
    }

    if(l == r) {
        ugly_code = true;
        return;
    }
    if(c[u][l]) {
        if(c[u][r]) {
            u--;
        }else {
            l--;
        }
    }
    if(c[d][r]) {
        d++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> T;
    while(T--) {
        cin >> N;
        while(N--) {
            memset(c, 0, sizeof c);
            cin >> H >> W;

            char inp;
            for(int i = 3; i < H+3; i++) {
                for(int j = 3; j < W+3; j++) {
                    cin >> inp;
                    c[i][j] = (inp == '*');
                }
            }

            l=u=999;
            r=d=-1;
            find_edges();

            if(ugly_code) {
                cout << 1;
                continue;
            }

            vector<int> rows;
            for(auto row : {u, (u+d)/2, d}) {
                rows.push_back(0);
                for(int col = l+1; col < r; col++)
                    if(c[row][col])
                        rows.back() = 1;
            }

            vector<int> cols;
            for(auto col : {l, r}) {
                cols.push_back(0);
                for(int row = u+1; row < (u+d)/2; row++)
                    if(c[row][col])
                        cols.back() = 1;
                cols.push_back(0);
                for(int row = (u+d)/2+1; row < d; row++)
                    if(c[row][col])
                        cols.back() = 1;
            }

            string ans;
            for(auto row : rows)
                ans += row + '0';
            for(auto col : cols)
                ans += col + '0';

            cout << solve[ans];
        }
        cout << '\n';
    }
}