#include <bits/stdc++.h>

using namespace std;

int ans = 0;
string S, T;

void shift() {
    for(char &c : S) {
        if(c == 'a')
            c = 'z';
        else
            c -= 1;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> S >> T;

    for(; ans <= 26; ans++) {
        if(S.find(T) != string::npos)
            break;
        shift();
    }

    cout << ans << '\n' << S << '\n';
}