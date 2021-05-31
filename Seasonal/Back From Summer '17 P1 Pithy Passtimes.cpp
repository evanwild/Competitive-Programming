#include <bits/stdc++.h>

using namespace std;

int N, ans = 0;
string inp;

int main() {
    cin >> N;
    while(N--) {
        cin >> inp;
        if(inp.size() <= 10) {
            ++ans;
        }
    }
    cout << ans << endl;
}