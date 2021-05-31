#include <bits/stdc++.h>
using namespace std;

int N, M, ans, ans_dist = -1;
vector<string> dig = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

void make_pal(string x) {
    if (x.size() >= 9) return;

    if (x[0] != '0') {
        int y = stoi(x);

        if (y >= N && y <= M) {
            int dist = min(y - N, M - y);
            if (dist > ans_dist) {
                ans_dist = dist;
                ans = y;
            }
        }
    }

    for (auto c : dig) {
        if (x.size() >= 7 && c == "0") continue;
        make_pal(c + x + c);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (auto c : dig) {
        make_pal(c);
        make_pal(c + c);
    }

    cout << ans << '\n';
}