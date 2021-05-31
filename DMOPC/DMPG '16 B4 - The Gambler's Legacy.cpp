#include <bits/stdc++.h>

using namespace std;

int T, M;

int f(int m) {
    int dig = log10(m) + 1;
    int ans = 0;
    while(m) {
        ans += pow(m%10, dig);
        m /= 10;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> T;

    while(T--) {
        cin >> M;
       
        int L = 0;
        unordered_map<int, int> prev;

        while(1) {
            if(M == f(M)) {
                cout << "Equilibrium: Bob's investment becomes $" << M << " after " << L << " second(s)!\n";
                break;
            }

            if(prev.count(M)) {
                cout << "Instability: Loop of length " << L-prev[M] << " encountered after " << prev[M] << " second(s)!\n";
                break;
            }

            prev[M] = L;
            M = f(M);
            ++L;
        }
    }    
}