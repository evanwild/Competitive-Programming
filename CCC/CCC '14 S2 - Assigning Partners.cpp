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

int N, good = 1;
string names[30], inp;
unordered_map<string, string> pairs;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    for (int i = 0; i < N; i++) cin >> names[i];

    for (int i = 0; i < N; i++) {
        cin >> inp;

        if (inp == names[i]) good = 0;

        if (pairs.count(inp))
            if (inp != pairs[names[i]]) good = 0;

        pairs[names[i]] = inp;
        pairs[inp] = names[i];
    }

    cout << (good ? "good\n" : "bad\n");
}