#include <bits/stdc++.h>

using namespace std;

int N, flip=0, ans=0; char s[1000005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++)
        cin >> s[i];
    
    for(int i = N-1; i >= 0; i--) {
        if((s[i] == '1' && !flip) || (s[i] == '0' && flip)) {
            flip = !flip;
            ans++;
        }
    }

    cout << ans << '\n';
}