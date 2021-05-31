#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>

using namespace std;

int n, s;
int rating[105], space[105];
int memo[105][30005]; 

int max_rating(int i, int left) {

    if(memo[i][left] != -1) {
        return memo[i][left];
    }

    if(i < 1) {
        return 0;
    }

    int result;

    if(space[i] > left) {
        result = max_rating(i-1, left);
    }else {
        result = max(
            rating[i] + max_rating(i-1, left-space[i]),
            max_rating(i-1, left)
        );
    }

    memo[i][left] = result;
    return result;
}

int main() {

    int tests = 5;
    while(tests--) {
        cin >> s >> n;

        string title;
        for(int i = 1; i <= n; i++) {
            cin >> title >> rating[i] >> space[i];
        }

        memset(memo, -1, sizeof memo);
        cout << max_rating(n, s) << endl;
    }

    return 0;
}