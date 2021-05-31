#include <bits/stdc++.h>
using namespace std;
#define int long long

int N;

int modular_pow(int base, int pow, int mod) {
    if(pow == 0) return 1;
    if(pow == 1) return base;
    int ans = modular_pow(base, pow/2, mod);
    
    ans = ((ans % mod) * ans) % mod;

    if(pow % 2 != 0)
        ans = (ans*base) % mod;

    return ans;
}

bool single_test(int A) {
    int exp = N-1;
    while(exp % 2 == 0) {
        exp /= 2;
    }

    if(modular_pow(A, exp, N) == 1) {
        return true;
    }

    while(exp < N-1) {
        if(modular_pow(A, exp, N) == N-1) {
            return true;
        }

        exp *= 2;
    }

    return false;
}

bool is_prime() {
    for(int i = 0; i < 40; i++) {
        int A = rand() % (N-2) + 2;
        if(!single_test(A)) {
            return false;
        }
    }
    return true;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    if(N <= 2) {
        cout << 2 << '\n';
        return 0;
    }

    if(N % 2 == 0)
        ++N;

    while(1) {
        if(is_prime()) {
            cout << N << '\n';
            break;
        }
        N += 2;
    }
}