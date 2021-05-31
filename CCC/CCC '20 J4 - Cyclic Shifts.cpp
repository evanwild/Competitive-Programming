#include <bits/stdc++.h>

using namespace std;

string T, S;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> T >> S;

    for(int i = 0; i <= S.size(); i++) {

        if(T.find(S) != string::npos) {
            cout << "yes\n";
            return 0;
        }

        string x = S.substr(S.size()-1, 1);
        S.pop_back();
        S = x + S;
    }

    cout << "no\n";
}