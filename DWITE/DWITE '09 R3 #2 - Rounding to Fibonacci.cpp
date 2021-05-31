#include <bits/stdc++.h>

using namespace std;

int N, fib[45] = {1, 1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    for(int i = 2; i < 45; i++)
        fib[i] = fib[i-1] + fib[i-2];

    for(int i = 0; i < 5; i++) {
        cin >> N;
        
        int best = 0;
        for(int j = 1; j < 45; j++)
            if(abs(fib[j]-N) <= abs(fib[best]-N))
                best = j;

        cout << fib[best] << '\n';
    }
}