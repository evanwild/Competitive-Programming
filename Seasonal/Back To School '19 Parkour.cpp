#include <bits/stdc++.h>

using namespace std;

int X, Y, H, W, T;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> X >> Y >> H >> W >> T;

    int x = 0, y = 0;

    while(1) {

        if(x >= X && y >= Y) {
            cout << "YES\n";
            return 0;
        }

        T--;

        if(T == 0) {
            cout << "NO\n";
            return 0;
        }

        if(X - x < Y - y) {
            x++;
            y += 2;
        }else {
            x += 2;
            y++;
        }
    }
}