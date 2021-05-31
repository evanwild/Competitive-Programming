#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int clubs[33];
int n;
bool dp[5281] = {false};
int dp_val[5281];

int min_strokes(int dist) {

    if(dp[dist]) return dp_val[dist];

    int result;

    if(dist == 0) {
        result = 0;
    }else if(clubs[0] > dist) {
        result = 100000;
    }else {

        vector<int> best_options;
        for(int i = 1; i <= n; i++) {
            if(dist-clubs[i] >= 0) {
                best_options.push_back(min_strokes(dist-clubs[i]));
            }
        }

        if(best_options.size() != 0) {
            result = 1 + *min_element(best_options.begin(), best_options.end());
        }
    }
    dp[dist] = true;
    dp_val[dist] = result;
    return result;
}

int main() {

    int dist;
    cin >> dist >> n;

    for(int i = 1; i <= n; i++) {
        cin >> clubs[i];
    }

    sort(clubs+1, clubs+n+1);

    int s = min_strokes(dist);

    if(s > 100000) {
        cout << "Roberta acknowledges defeat." << endl;
    }else {
        cout << "Roberta wins in " << s << " strokes." << endl;
    }

    return 0;
}