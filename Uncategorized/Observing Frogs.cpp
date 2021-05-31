#include <bits/stdc++.h>

using namespace std;

long long N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    if(N % 2 == 0)
        cout << 2*(N/2)*(N/2) << '\n';
    else
        cout << 2*(N/2)*(N+1)/2 << '\n';
}