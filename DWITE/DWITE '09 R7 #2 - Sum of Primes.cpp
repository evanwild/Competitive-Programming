#include <iostream>

using namespace std;

bool is_prime(int n) {
    if(n <= 2) {
        return (n == 2);
    }
    if(n % 2 == 0) {
        return false;
    }
    for(int i = 3; i*i <= n; i+=2) {
        if(n%i == 0) {
            return false;
        }
    }
    return true;
}

int main() {

    int tests = 5;
    int n;
    while(tests--) {
        cin >> n;
        int ans = 0;
        for(int i = 2; i <= n; i++) {
            if(is_prime(i)) {
                ans += i;
            }
        }
        cout << ans << endl;
    }

    return 0;
}