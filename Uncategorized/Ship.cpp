#include <bits/stdc++.h>

using namespace std;

string H, s="BFTLC";
bool a = 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> H;

    for(char c : s) {
        if(H.find(c) == string::npos) {
            cout << c << '\n';
            a = 0;
        }
    }

    if(a)
        cout << "NO MISSING PARTS\n";
}