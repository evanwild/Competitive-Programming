#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, p;
    cin >> n >> p;

    string name;
    int m, cs, e;

    pair<int, string> mx = {INT_MIN, ""};
    pair<int, string> mn = {INT_MAX, ""};

    while (n--) {
        cin >> name >> m >> cs >> e;
        int score = floor(4 * sqrt(m) + 3 * powl(cs, p) - 4 * e);
        mx = max(mx, {score, name});
        mn = min(mn, {score, name});
    }

    cout << mx.second << ' ' << mx.first << '\n';
    cout << mn.second << ' ' << mn.first << '\n';
}