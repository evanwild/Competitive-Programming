#include <iostream>

using namespace std;

int main() {

    long long n;
    cin >> n;

    if(n == 3) {
        cout << 0 << endl;
    }else {
        cout << (n*(n-1)*(n-2)*(n-3))/24 << endl;
    }

    return 0;
}