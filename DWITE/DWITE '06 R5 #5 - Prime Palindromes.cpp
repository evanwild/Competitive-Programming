#include <bits/stdc++.h>

using namespace std;

int L, U, ans, tc=5;

bool is_prime() {
    if(L == 2)
        return 1;
    if(L % 2 == 0)
        return 0;
    for(int i = 3; i*i <= L; i+=2)
        if(L % i == 0)
            return 0;
    return 1;
}

bool is_pal() {
    int x = L;
    int rev = 0;

    while(x) {
        rev = rev*10 + x%10;
        x /= 10;
    }
    return (rev == L);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    while(tc--) {
        cin >> L >> U;

        ans = 0;

        if(L == 2)
            ans++;

        if(L % 2 == 0)
            L++;

        while(L <= U) {
            if(is_prime() && is_pal())
                ans++;
            L += 2;
        }
        cout << ans << '\n';
    }
}