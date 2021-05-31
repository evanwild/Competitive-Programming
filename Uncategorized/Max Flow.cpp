#include <bits/stdc++.h>

using namespace std;

int T, N, F, ans;

int main() {
    cin >> T;
    while(T--) {
        cin >> N;
        ans = 0;
        while(N--) {
            cin >> F;
            ans = max(ans, F);
        }
        cout << ans << endl;
    }
}