#include <iostream>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

string k;
int d;
vector<int> num;
long long dp[10005][101][2];

long long solve(int pos, int sum_so_far, bool less) {
    
    if(pos == num.size()) {
        if(sum_so_far == 0) {
            return 1;
        }
        return 0;
    }

    if(dp[pos][sum_so_far][less] != -1) {
        return dp[pos][sum_so_far][less];
    }

    long long res = 0;
    int limit = 9;

    if(!less) {
        limit = num.at(pos);
    }

    for(int digit = 0; digit <= limit; digit++) {
        bool new_less = less;
        if(!less && digit < limit) {
            new_less = true;
        }
        res += solve(pos+1, (sum_so_far+digit)%d, new_less) % 1000000007;
    }

    return dp[pos][sum_so_far][less] = res % 1000000007;
}

void str_to_vector(const string &s) {
    for(char c : s) {
        num.push_back(c - '0');
    }
}

int main() {

    cin >> k >> d;

    str_to_vector(k);
    memset(dp, -1, sizeof dp);
    int ans = solve(0, 0, 0);
    
    cout << (ans-1) << endl;

    return 0;
}