#include <bits/stdc++.h>

using namespace std;

int N;
string inp, v = "aeiou", syl[4];

string last_syl(string &s) {
    int last_v = -1;
    for(int i = 0; i < s.size(); i++)
        if(v.find(s[i]) != string::npos)
            last_v = i;
    return (last_v == -1 ? s : s.substr(last_v, s.size() - last_v));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;
    cin.ignore();

    while(N--) {
        for(int i = 0; i < 4; i++) {
            getline(cin, syl[i]);

            syl[i] = syl[i].substr(syl[i].find_last_of(' ') + 1);

            for(char &c : syl[i])
                c = tolower(c);

            syl[i] = last_syl(syl[i]);
        }

        if(syl[0] == syl[1] && syl[1] == syl[2] && syl[2] == syl[3])
            cout << "perfect\n";
        else if(syl[0] == syl[1] && syl[2] == syl[3])
            cout << "even\n";
        else if(syl[0] == syl[2] && syl[1] == syl[3])
            cout << "cross\n";
        else if(syl[0] == syl[3] && syl[1] == syl[2])
            cout << "shell\n";
        else
            cout << "free\n";
    }
}