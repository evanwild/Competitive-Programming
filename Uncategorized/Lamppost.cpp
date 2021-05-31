#include <bits/stdc++.h>

using namespace std;

int N, C, c1, c2;
int con[1000001] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> C;

    while(C--) {
        cin >> c1 >> c2;
        con[c1]++;
        con[c2]++;
    }

    int idx = 0;
    
    for(int i = 1; i <= N; i++)
        if(con[i] >= con[idx])
            idx = i;

    cout << idx << '\n';
}