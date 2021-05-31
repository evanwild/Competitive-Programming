#include <bits/stdc++.h>
using namespace std;

int S, M, L;

int main()  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> S >> M >> L;

    cout << (S+2*M+3*L >= 10 ? "happy\n" : "sad\n");

    return 0;
}