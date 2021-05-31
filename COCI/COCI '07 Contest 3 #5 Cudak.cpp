#include <iostream>
#include <deque>
#include <string.h>

using namespace std;

bool first_found = false;
long long first;
deque<int> num1, num2;
long long a, b;
long long dp[17][136][2][2];
int s;

long long solve(int pos, int sum_so_far, bool less, bool more, long long num) {
    if(sum_so_far > s) {
        return 0;
    }
    
    if(pos == num2.size()) {
        if(sum_so_far == s) {
            if(!first_found) {
                first = num;
                first_found = true;
            }
            return 1;
        }
        return 0;
    }

    if(dp[pos][sum_so_far][less][more] != -1) {
        return dp[pos][sum_so_far][less][more];
    }

    long long res = 0;
    int limit = 9;
    int min = 0;

    if(!less) {
        limit = num2.at(pos);
    }

    if(!more) {
        min = num1.at(pos);
    }

    for(int digit = min; digit <= limit; digit++) {
        bool new_less = less;
        bool new_more = more;
        if(!less && digit < limit) {
            new_less = true;
        }
        if(!more && digit > min) {
            new_more = true;
        }
        if(sum_so_far + digit <= s) {
            res += solve(pos+1, sum_so_far+digit, new_less, new_more, num*10+digit);
        }
    }

    return dp[pos][sum_so_far][less][more] = res;
}

void ll_to_vector1(long long n) {
    num1.clear();
    while(n) {
        num1.push_front(n % 10);
        n /= 10;
    }
    while(num1.size() < num2.size()) {
        num1.push_front(0);
    }
}

void ll_to_vector2(long long n) {
    num2.clear();
    while(n) {
        num2.push_front(n % 10);
        n /= 10;
    }
}

int main() {

    cin >> a >> b >> s;

    ll_to_vector2(b);
    ll_to_vector1(a);
    memset(dp, -1, sizeof dp);
    long long ans = solve(0, 0, 0, 0, 0);
    
    cout << ans << endl;
    cout << first << endl;

    return 0;
}