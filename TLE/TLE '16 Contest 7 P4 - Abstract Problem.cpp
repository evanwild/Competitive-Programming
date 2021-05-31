#include <bits/stdc++.h>

using namespace std;

long long X, T;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> T;

    while(T--) {
        cin >> X;

        int ans = 0;
        while(X) {
            if(X % 2 == 0) {
                X /= 2;
            }else {
                if(X == 3 || X % 4 == 1)
                    X -= 1;
                else
                    X += 1;
            }
            ans++;
        }
        
        cout << ans << '\n';
    }
}