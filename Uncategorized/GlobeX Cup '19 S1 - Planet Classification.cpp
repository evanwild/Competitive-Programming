#include <bits/stdc++.h>

using namespace std;

int N, K, a;
unordered_map<int, int> t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> K;

    while(N--) {
        cin >> a;
        cout << t[a] << '\n';
        t[a]++;
    }

    cout << t.size() << '\n';
}