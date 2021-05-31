#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using pi = pair<int, int>;
#define f first
#define s second
#define mp make_pair

string N, H;
ll pows[200005], hashs[200005], N_hash = 0, m = 1e9 + 7;
ll pows2[200005], hashs2[200005], N_hash2 = 0, m2 = 1e9 + 9;
set<pair<ll, ll>> ans;
unordered_map<char, int> N_freq, H_freq;

ll get_hash(int l, int r) {
    return (hashs[r] - (hashs[l - 1] * pows[r - l + 1]) % m + m) % m;
}

ll get_hash2(int l, int r) {
    return (hashs2[r] - (hashs2[l - 1] * pows2[r - l + 1]) % m2 + m2) % m2;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 'a'; i <= 'z'; i++) {
        H_freq[i] = 0;
        N_freq[i] = 0;
    }

    cin >> N >> H;

    pows[0] = 1;
    pows2[0] = 1;
    for (int i = 1; i <= sz(H); i++) {
        pows[i] = (23 * pows[i - 1]) % m;
        hashs[i] = (23 * hashs[i - 1] + H[i - 1]) % m;

        pows2[i] = (131 * pows2[i - 1]) % m2;
        hashs2[i] = (131 * hashs2[i - 1] + H[i - 1]) % m2;
    }
    for (int i = 1; i <= sz(N); i++) {
        N_hash = (23 * N_hash + N[i - 1]) % m;
        N_hash2 = (131 * N_hash2 + N[i - 1]) % m2;
        N_freq[N[i - 1]]++;
        H_freq[H[i - 1]]++;
    }

    for (int i = 1; i <= sz(H) - sz(N) + 1; i++) {
        if (i != 1) {
            H_freq[H[i - 2]]--;
            H_freq[H[i + sz(N) - 2]]++;
        }
        if (H_freq == N_freq)
            ans.insert(
                mp(get_hash(i, i + sz(N) - 1), get_hash2(i, i + sz(N) - 1)));
    }

    cout << ans.size() << '\n';
}