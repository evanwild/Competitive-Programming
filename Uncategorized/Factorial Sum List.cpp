#include <bits/stdc++.h>
using namespace std;

int N;

int fact(int x) {
    if (x == 0) return 1;
    return x * fact(x - 1);
}

int digit_fact(int x) {
    int ans = 0;
    while (x) {
        ans += fact(x % 10);
        x /= 10;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (1) {
        cin >> N;
        if (N == 0) break;
        set<int> ans;
        while (1) {
            ans.insert(N);
            N = digit_fact(N);
            if (ans.find(N) != ans.end()) break;
        }

        cout << ans.size() + 1 << '\n';
    }
}