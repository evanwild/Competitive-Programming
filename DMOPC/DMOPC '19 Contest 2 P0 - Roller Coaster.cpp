#include <iostream>

using namespace std;

int main() {

    int n, h_min, h_max;
    cin >> n >> h_min >> h_max;

    int ans = 0;
    for(int i = 0; i < n; i++) {
        int h_i;
        cin >> h_i;
        if(h_i >= h_min && h_i <= h_max) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}