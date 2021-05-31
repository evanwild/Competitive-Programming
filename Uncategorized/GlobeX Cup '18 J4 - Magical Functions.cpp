#include <iostream>
#include <math.h>

using namespace std;

int a,b,c,d,e,N;

unsigned long long f(int x) {
    if(x == 0) {
        return e;
    }
    return (a * f(floor(x/b)) + c * f(floor(x/d))) % 1000000007;
}

int main() {
    cin >> a >> b >> c >> d >> e >> N;
    cout << f(N) << endl;
}