#include <iostream>
#include <string>

using namespace std;

int main() {

    string a, b;
    cin >> a >> b;

    int diff = 0;
    for(int i = 0; i < a.size(); i++) {
        if(a[i] != b[i]) {
            diff++;
        }
    }

    if(diff == 1) {
        cout << "LARRY IS SAVED!" << endl;
    }else {
        cout << "LARRY IS DEAD!" << endl;
    }

    return 0;
}