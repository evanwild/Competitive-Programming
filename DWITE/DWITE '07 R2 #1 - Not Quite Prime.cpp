#include <bits/stdc++.h>

using namespace std;

int N, TC=5, prime[10000000];
vector<int> primes;

void sieve() {
    memset(prime, -1, sizeof prime);
    for(int i = 2; i*i <= 9999999; i++)
        if(prime[i])
            for(int j = i*i; j <= 9999999; j += i)
                prime[j] = 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    sieve();
    while(TC--) {
        cin >> N;
        bool sp = 0;
        for(int i = 2; i <= N/2; i++)
            for(int j = 2; j <= N/2; j++)
                if(prime[i] && prime[j] && i*j == N)
                        sp = 1;
        cout << (sp ? "semiprime\n" : "not\n");
    }
}