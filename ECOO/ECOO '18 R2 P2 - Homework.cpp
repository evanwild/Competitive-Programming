#include <bits/stdc++.h>

using namespace std;

int N, D, TC=10, day;
double W;

vector<pair<double, int>> hw;
set<int> slots;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    while(TC--) {

        cin >> N;

        hw.clear();
        slots.clear();

        day = -1;
        while(N--) {
            cin >> D >> W;
            hw.push_back({W, D});
            day = max(day, D-1);
        }
        sort(hw.begin(), hw.end());
        reverse(hw.begin(), hw.end());

        for(int i = -day; i <= 0; i++)
            slots.insert(i);

        double ans = 0;
        for(auto x : hw) {
            auto s = slots.lower_bound(-x.second + 1);
            if(s != slots.end()) {
                ans += x.first;
                slots.erase(*s);
            }
        }

        cout << fixed << setprecision(4) << ans << '\n';
    }
}