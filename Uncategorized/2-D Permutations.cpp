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

int N, M, Q, q;
int freq[25000005];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M >> Q;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            int lower = i * j;
            int higher = (N - i + 1) * (M - j + 1) - 1;

            freq[lower]++;
            freq[N * M - higher + 1]--;
        }
    }

    for (int i = 1; i <= N * M; i++)
        freq[i] += freq[i - 1];

    while (Q--) {
        cin >> q;
        cout << freq[q] << '\n';
    }
}