#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, M;
string S[50005], X;
int pows[50005], hashs[50005];
int dp[50005];

unordered_set<int> lengths;
unordered_map<int, int> hash_freq;

int get_hash(int l, int r) {
    return hashs[r] - hashs[l-1] * pows[r-l+1];
}

void hash_rotations(const string &T) {
    unordered_set<int> unique;

    int hsh = 0;
    for(char c : T)
        hsh = hsh*131 + c;
    unique.insert(hsh);
    
    for(int i = 1; i < T.size(); i++) {
        hsh = hsh*131 + T[i-1];
        hsh -= T[i-1] * pows[T.size()];
        unique.insert(hsh);
    }

    for(int u : unique)
        hash_freq[u]++;
}

int solve(int i) {
    if(i == X.size())
        return 1;
    if(dp[i] != -1)
        return dp[i];

    int ans = 0;
    for(int l : lengths) {
        if(i + l <= X.size()) {
            int hsh = get_hash(i+1, i+l);
            if(hash_freq.count(hsh))
                ans = (ans + hash_freq[hsh] * solve(i+l)) % M;
        }
    }
            
    return dp[i] = ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    memset(dp, -1, sizeof dp);

    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> S[i];
        lengths.insert(S[i].size());
    }
    cin >> X;

    pows[0] = 1;
    for(int i = 1; i <= X.size(); i++) {
        hashs[i] = hashs[i-1] * 131 + X[i-1];
        pows[i] = pows[i-1] * 131;
    }

    for(int i = 0; i < N; i++)
        hash_rotations(S[i]);
    
    cout << solve(0) << '\n';
}