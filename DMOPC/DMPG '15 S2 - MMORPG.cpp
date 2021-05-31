#include <bits/stdc++.h>

using namespace std;

int R, N, x, y, ans=0;

struct Song {
    int x, y, w, l, u=1;
} songs[1005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> R >> N;

    for(int i = 0; i < R; i++) {
        Song& s = songs[i];
        cin >> s.x >> s.y >> s.w >> s.l;
    }

    while(N--) {
        cin >> x >> y;
        for(int i = 0; i < R; i++) {
            Song& s = songs[i];
            if(s.u) {
                if(x >= s.x && x < s.x+s.w && y >= s.y && y < s.y+s.l) {
                    ans++;
                    s.u = 0;
                }
            }
        }
    }
    cout << ans << '\n';
}