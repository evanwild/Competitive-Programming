#include <bits/stdc++.h>

using namespace std;

int a, b, ans=0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> a >> b;

    for(int i = 1; i <= 22; i++)
        if(i*i*i*i*i*i <= b && i*i*i*i*i*i >= a)
            ans++;

    cout << ans << '\n';
}