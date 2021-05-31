#include <bits/stdc++.h>

using namespace std;

int tc = 5, N, ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    while(tc--) {
        cin >> N;
        ans = 0;

        if(N % 2 == 0) {
            N /= 2;
            ans++;
        }

        for(int i = 3; i <= N; i += 2) {
            if(N % i == 0) {
                N /= i;
                ans++;
            }
        }

        cout << (ans == 3 ? "valid" : "not") << '\n';
    }
}