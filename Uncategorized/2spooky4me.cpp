#include <bits/stdc++.h>
using namespace std;

class WildMap {
public:
    WildMap(int);
    void update(int, int, int);
    int count_below(int);
private:
    map<int, int> diff;
};

WildMap::WildMap(int max) {
    diff[max+1] = 0;
}

void WildMap::update(int l, int r, int x) {
    diff[l] += x;
    diff[r+1] -= x;
}

int WildMap::count_below(int x) {
    int run = 0, ans = 0;
    pair<int, int> prev = {1, 0};
    for(auto d : diff) {
        if(run < x)
            ans += d.first - prev.first;
        run += d.second;
        prev = d;
    }
    return ans;
}

int N, L, S, a, b, s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> L >> S;

    WildMap wild_map(L);

    while(N--) {
        cin >> a >> b >> s;
        wild_map.update(a, b, s);
    }

    cout << wild_map.count_below(S) << '\n';
}