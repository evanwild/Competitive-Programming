#include <iostream>

using namespace std;

int main() {

    double r, h;
    cin >> r >> h;

    const double PI = 3.14159265358979;
    cout << PI*r*r*(h/3) << endl;

    return 0;
}