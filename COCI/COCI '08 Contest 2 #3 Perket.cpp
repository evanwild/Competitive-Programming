#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int N;
vector<pair<int, int>> ing;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;
    ing.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> ing[i].first >> ing[i].second;
    }

    int ans = LLONG_MAX;
    do {
        int sour = 1;
        int bitter = 0;
        for (int i = 0; i < N; i++) {
            sour *= ing[i].first;
            bitter += ing[i].second;
            ans = min(ans, abs(sour - bitter));
        }
    } while (next_permutation(ing.begin(), ing.end()));

    cout << ans << endl;
}