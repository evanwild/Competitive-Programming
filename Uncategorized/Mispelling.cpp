#include <bits/stdc++.h>
using namespace std;

int N, M;
string S;

int main() {
    cin >> N;
    for(int i = 1; i <= N; ++i) {
        cin >> M;
        cout << i << ' ';
        cin.ignore();
        getline(cin, S);

        for(int j = 1; j <= S.size(); ++j)
            if(j != M)
                cout << S[j - 1];
        cout << endl;
    }
}