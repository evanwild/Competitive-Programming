#include <bits/stdc++.h>

using namespace std;

int Q, N, K;
long long l[31];
string f0 = "Good writing is good writing is good writing.";

string a = "Good writing is good ";
string b = " writing is good ";
string c = " is good writing.";

char solve(int n, int k) {
    if(k >= l[n])
        return '.';
    if(n == 0)
        return f0[k];
    if(k < 21)
        return a[k];

    if(k >= l[n]-17)
        return c[17 - l[n] + k];

    if(k >= l[n-1]+21 && k < l[n]-l[n-1]-17)
        return b[k - 21 - l[n-1]];

    if(k > 38+l[n-1])
        return solve(n-1, k-l[n-1]-38);

    return solve(n-1, k-21);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    l[0] = 45;
    for(int i = 1; i <= 30; i++)
        l[i] = 55 + 2*l[i-1];

    cin >> Q;
    while(Q--) {
        cin >> N >> K;
        cout << solve(N, K-1) << '\n';
    }
}