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

int N;
string S;

bool valid() {
    int o = 0;
    for (char c : S) {
        if (c == '(')
            o++;
        else if (c == ')')
            o--;
        if (o < 0) break;
    }
    return (o == 0);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    while (N--) {
        cin >> S;
        cout << (valid() ? "YES\n" : "NO\n");
    }
}