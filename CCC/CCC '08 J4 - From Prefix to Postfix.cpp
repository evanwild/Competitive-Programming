#include <bits/stdc++.h>

using namespace std;

vector<char> e;

void solve(int l, int r) {
    if(l == r)
        cout << e[l] << ' ';
    else if(r - l + 1 == 3)
        cout << e[l+1] << ' ' << e[r] << ' ' << e[l] << ' ';
    else if(isdigit(e[l+1]) && isdigit(e[l+2])) {
        cout << e[l+1] << ' ' << e[l+2] << ' ' << e[l] << ' ';
        solve(l+3, r);
    }else if(isdigit(e[l+1]) && !isdigit(e[l+2])) {
        cout << e[l+1] << ' ';
        solve(l+2, r);
        cout << e[l] << ' ';
    }else if(isdigit(e[r]) && isdigit(e[r-1]) && isdigit(e[r-2])) {
        solve(l+1, r-1);
        cout << e[r] << ' ' << e[l] << ' ';
    }else {
        solve(l+1, r);
        cout << e[l] << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    while(1) {
        string S;
        getline(cin, S);

        if(S == "0")
            break;

        e.clear();

        for(int i = 0; i < S.size(); i += 2)
            e.push_back(S[i]);

        solve(0, e.size()-1);
        cout << '\n';
    }
}