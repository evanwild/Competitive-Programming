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

string S;
vi us;
vector<string> perms;
unsigned long long ans = 0;

void make_perms(string x = "") {
    if (sz(x) == sz(us))
        perms.pb(x);
    else {
        make_perms(x + 'A');
        make_perms(x + 'C');
        make_perms(x + 'L');
    }
}

bool vow(char c) {
    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

unsigned long long solve(string s) {}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> S;
    for (int i = 0; i < sz(S); i++)
        if (S[i] == '_') us.pb(i);
    make_perms();

    for (string p : perms) {
        for (int i = 0; i < sz(p); i++) S[us[i]] = p[i];

        bool valid = 1;
        int L = 0;

        for (int i = 0; i < sz(S); i++) {
            if (i != 0 && i != sz(S) - 1) {
                if (vow(S[i - 1]) && vow(S[i]) && vow(S[i + 1])) valid = 0;
                if (!vow(S[i - 1]) && !vow(S[i]) && !vow(S[i + 1])) valid = 0;
            }
            if (S[i] == 'L') L++;
        }

        if (!valid || !L) continue;

        unsigned long long sub_ans = 1;
        for (char c : p) {
            if (c == 'C') sub_ans *= 20;
            if (c == 'A') sub_ans *= 5;
        }
        ans += sub_ans;
    }
    cout << ans << '\n';
}