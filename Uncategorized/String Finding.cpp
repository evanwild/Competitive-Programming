#include <bits/stdc++.h>
using namespace std;
#define int long long

string S, T;
int pows[1000001], hashs[1000001], ans=0, t_hash=0;
const int m = 1e9+7;

int get_hash(int l, int r) {
    return (hashs[r] - (hashs[l-1] * pows[r-l+1]) % m + m) % m;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> S >> T;

    pows[0] = 1;
    for(int i = 1; i <= S.size(); ++i) {
        pows[i] = (131*pows[i-1]) % m;
        hashs[i] = (131*hashs[i-1] + S[i-1]) % m;
    }

    for(int i = 1; i <= T.size(); ++i)
        t_hash = (131*t_hash + T[i-1]) % m;

    for(int i = S.size()-T.size()+1; i >= 1; --i)
        if(get_hash(i, i+T.size()-1) == t_hash)
            ans = i;
    
    cout << ans-1 << '\n';
}