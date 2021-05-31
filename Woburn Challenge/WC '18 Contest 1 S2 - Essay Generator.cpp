#include <bits/stdc++.h>

using namespace std;

int W;
string a = "abcdefghijklmnopqrstuvwxyz";

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> W;

    for(int i = 0; i < 26 && W; i++) {
        cout << a[i] << ' ';
        W--;
    }

    for(int i = 0; i < 26; i++)
        for(int j = 0; j < 26 && W; j++) {
            cout << a[i] << a[j] << ' ';
            W--;
        }

    for(int i = 0; i < 26; i++)
        for(int j = 0; j < 26; j++)
            for(int k = 0; k < 26 && W; k++) {
                cout << a[i] << a[j] << a[k] << ' ';
                W--;
            }
}