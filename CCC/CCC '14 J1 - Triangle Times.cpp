#include <iostream>

using namespace std;

int main() {

    int a1;
    int a2;
    int a3;

    cin >> a1 >> a2 >> a3;

    if(a1 + a2 + a3 != 180) {
        cout << "Error" << endl;
    }else if(a1 == 60 && a2 == 60 && a3 == 60) {
        cout << "Equilateral" << endl;
    }else if(a1 != a2 && a1 != a3 && a2 != a3) {
        cout << "Scalene" << endl;
    }else {
        cout << "Isosceles" << endl;
    }

    return 0;
}