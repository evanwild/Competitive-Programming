#include <bits/stdc++.h>
using namespace std;
#define int long long

int s_len, T_len;
string s, T;
unordered_map<char, set<int>> idx;

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> s_len >> T_len;
    cin >> s >> T;

    for (int i = 0; i < s.size(); i++) {
        idx[s[i]].insert(i);
    }

    int ans = s.size();
    int s_idx = 0;

    for (int i = 0; i < T.size(); i++) {
        char c = T[i];

        if (!idx.count(c)) {
            cout << "-1\n";
            return 0;
        }

        auto nxt_idx = idx[c].lower_bound(s_idx);

        if (nxt_idx == idx[c].end()) {
            ans += s.size();
            s_idx = 0;
        }

        nxt_idx = idx[c].lower_bound(s_idx);
        s_idx = *nxt_idx + 1;
    }

    ans -= s.size() - s_idx;

    cout << ans << '\n';
}