#include <bits/stdc++.h>

using namespace std;

int r;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    while(1) {
        cin >> r;

        if(r == 0)
            break;

        int ans = 1 + 4*r;

        for(int x = 1; x <= r; x++)
            for(int y = 1; y <= r; y++)
                if(x*x + y*y <= r*r)
                    ans += 4;

        cout << ans << '\n';
    }
}