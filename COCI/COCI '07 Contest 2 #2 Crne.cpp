#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    cout << (floor(N/2) + 1)*(N - floor(N/2) + 1) << '\n'; 
}