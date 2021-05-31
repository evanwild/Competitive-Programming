#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<int> primes;

void sieve(int n) {
    vector<bool> is_prime(n+1, true);
    for(int i = 2; i <= sqrt(n); i++) {
        if(is_prime.at(i)) {
            for(int j = i*i; j <= n; j+=i) {
                is_prime.at(j) = false;
            }
        }
    }
    for(int i = 2; i <= n; i++) {
        if(is_prime.at(i)) {
            primes.push_back(i);
        }
    }
}

int main() {

    int n, x;
    cin >> n >> x;
    sieve(n);

    int ans = 0;
    for(int lelei = 0; lelei < primes.size() && primes[lelei]<=n; lelei++) {
        for(int tuka = 0; tuka <= 1; tuka++) {
            if(n-primes[lelei]-tuka < 0) continue;
            ans += (n-primes[lelei]-tuka)/x+1;
        }
    }

    cout << ans << endl;

    return 0;
}