#include <bits/stdc++.h>

using namespace std;

int T, h;
double p;
char t, d;

unordered_map<char, double> tax = {{'A',1},{'B',0.9},{'C',0.8},{'D',0.71},{'E',0.65}};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> T;
    while(T--) {
        cin >> p >> h >> t >> d;

        double pay = p * min(h, 40);
        double over = p * 2 * max(0, h-40);

        cout << fixed << setprecision(2) << (pay + over)*tax[t] - (d == 'y' ? 10 : 0) << '\n';
    }
}