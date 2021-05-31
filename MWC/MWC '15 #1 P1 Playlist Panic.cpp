#include <iostream>
#include <algorithm>
using namespace std;

int N, M, S, X, Y, secs[1005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> M >> S;
        secs[i] = M*60 + S;
    }
    sort(secs, secs+N);

    cin >> X >> Y;

    int sum=0, ans=0;
    for(int i = 0; i < N; i++) {
        if(sum + secs[i] <= X*60 + Y) {
            ans++;
            sum += secs[i];
        }
    }
    
    cout << ans << '\n';
}