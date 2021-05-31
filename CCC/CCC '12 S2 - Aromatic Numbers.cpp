#include <bits/stdc++.h>

using namespace std;

string s;
int ans = 0;

map<char, int> vals = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> s;

    for(int i = 0; i < s.size(); i += 2) {
        int a = s[i] - '0';
        int r = vals[s[i+1]];

        if(vals[s[i+3]] > r)
            ans -= a*r;
        else
            ans += a*r;
    }

    cout << ans << '\n';
}