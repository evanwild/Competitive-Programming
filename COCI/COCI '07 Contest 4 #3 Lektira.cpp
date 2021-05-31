#include <bits/stdc++.h>
using namespace std;

string S, ans = "~";

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> S;
    for (int i = 1; i < S.size() - 1; i++) {
        for (int j = i; j < S.size() - 1; j++) {
            string rev;
            for (int k = i - 1; k >= 0; k--) rev += S[k];
            for (int k = j; k >= i; k--) rev += S[k];
            for (int k = S.size()-1; k > j; k--) rev += S[k];
            if (rev < ans) ans = rev;
        }
    }
    cout << ans << '\n';
}