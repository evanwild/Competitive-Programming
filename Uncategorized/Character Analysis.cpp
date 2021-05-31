#include <bits/stdc++.h>

using namespace std;

string a, b;
unordered_map<char, int> freq_a;
unordered_map<char, int> freq_b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> a >> b;

    for(char c : a) freq_a[c]++;
    for(char c : b) freq_b[c]++;

    for(char c : a) {
        if(freq_a[c] != freq_b[c]) {
            cout << c << '\n';
            break;
        }
    }
}