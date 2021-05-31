#include <bits/stdc++.h>
using namespace std;
#define LL unsigned long long

int N;
LL n;
const LL mod = 4294967296;

LL solve(LL x) {
    if(x == 0)
        return 1;
    if(x >= 34)
        return 0;
    return (x * solve(x-1)) % mod;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    while(N--) {
        cin >> n;
        cout << solve(n) << '\n';
    }
}