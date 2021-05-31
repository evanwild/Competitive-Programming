#include <bits/stdc++.h>

using namespace std;

int K, m, r;
bool g[101] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> K >> m;

    while(m--) {
        cin >> r;

        int x = 0;
        for(int i = 1; i <= K; i++) {
            if(!g[i]) {
                x++;
                if(x % r == 0) {
                    g[i] = 1;
                    x = 0;
                }
            }
        }
    }

    for(int i = 1; i <= K; i++)
        if(!g[i])
            cout << i << '\n';
}