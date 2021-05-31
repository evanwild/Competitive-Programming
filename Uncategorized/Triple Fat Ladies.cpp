#include <bits/stdc++.h>

using namespace std;

unsigned long long T, K;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> T;

    while(T--) {
        cin >> K;
        K++;

        while(1) {
            unsigned long long c = K*K*K;
            if(c%10 == 8 && (c/10)%10 == 8 && (c/100)%10 == 8) {
                cout << K << '\n';
                break;
            }
            K++;
        }
    }
}