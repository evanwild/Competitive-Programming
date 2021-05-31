#include <bits/stdc++.h>

using namespace std;

string S;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    getline(cin, S);

    int c = S.find(',');
    char last = S.back();
    S.pop_back();

    string h1 = S.substr(c+1, S.size()-c-1);
    while(h1[0] == ' ')
        h1 = h1.substr(1, h1.size() - 1);
    h1[0] = toupper(h1[0]);

    string h2 = S.substr(0, c);
    h2[0] = tolower(h2[0]);
    while(h2.back() == ' ')
        h2.pop_back();

    if(h1.empty()) {
        h2[0] = toupper(h2[0]);
        cout << h2 << last << '\n';
    }else if(h2.empty()) {
        cout << h1 << last << '\n';
    }else
        cout << h1 << ' ' << h2 << last << '\n';
}